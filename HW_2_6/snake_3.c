#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses/ncurses.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>

#define MIN_Y  2
double DELAY = 0.1;

#define SNAKE1_COLOR 1  
#define SNAKE2_COLOR 2  

enum {LEFT=1, UP, RIGHT, DOWN, STOP_GAME=KEY_F(10)};
enum {MAX_TAIL_SIZE=100, START_TAIL_SIZE=3, MAX_FOOD_SIZE=20, FOOD_EXPIRE_SECONDS=10,SEED_NUMBER=3,CONTROLS=2,START_LIVES=3};


// Здесь храним коды управления змейкой
struct control_buttons
{
    int down;
    int up;
    int left;
    int right;
} control_buttons;

struct control_buttons default_controls[CONTROLS] = {{KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT},
                                                    {'s', 'w', 'a', 'd'}};

/*
 Голова змейки содержит в себе
 x,y - координаты текущей позиции
 direction - направление движения
 tsize - размер хвоста
 *tail -  ссылка на хвост
 */
typedef struct snake_t
{
    int x;
    int y;
    int direction;
    size_t tsize;
    struct tail_t *tail;
    struct lives_t *lives;
    struct control_buttons controls;
} snake_t;

/*
 Хвост это массив состоящий из координат x,y
 */
typedef struct tail_t
{
    int x;
    int y;
} tail_t;


typedef struct lives_t
{
    int nbr_of_lives;
    int x;
    int y;
} lives_t;

/*
 Еда — это массив точек, состоящий из координат x,y, времени,
 когда данная точка была установлена, и поля, сигнализирующего,
 была ли данная точка съедена.
 */
struct food
{
    int x;
    int y;
    time_t put_time;
    char point;
    uint8_t enable;
} food[MAX_FOOD_SIZE];

void initFood(struct food f[], size_t size)
{
    struct food init = {0,0,0,0,0};
    for(size_t i=0; i<size; i++)
    {
        f[i] = init;
    }
}
/*
  Установка цвета 
 */
void setColor(int objectType){
    attroff(COLOR_PAIR(1));
    attroff(COLOR_PAIR(2));
    attroff(COLOR_PAIR(3));
    switch (objectType){
        case 1:{ // SNAKE1
            attron(COLOR_PAIR(1));
            break;
        }
        case 2:{ // SNAKE2
            attron(COLOR_PAIR(2));
            break;
        }
        case 3:{ // FOOD
            attron(COLOR_PAIR(3));
            break;
        }
    }
}

/*
 Обновить/разместить текущее зерно на поле
 */
void putFoodSeed(struct food *fp)
{
    int max_x=0, max_y=0;
    char spoint[2] = {0};
    getmaxyx(stdscr, max_y, max_x);
    mvprintw(fp->y, fp->x, " ");
    fp->x = rand() % (max_x - 1);
    fp->y = rand() % (max_y - 2) + 1; //Не занимаем верхнюю строку
    fp->put_time = time(NULL);
    fp->point = '$';
    fp->enable = 1;
    spoint[0] = fp->point;
    mvprintw(fp->y, fp->x, "%s", spoint);
}

/*
 Разместить еду на поле
 */
void putFood(struct food f[], size_t number_seeds)
{
	setColor(3);
    for(size_t i=0; i<number_seeds; i++)
    {
        putFoodSeed(&f[i]);
    }
}

void refreshFood(struct food f[], int nfood)
{  
	setColor(3);
    for(size_t i=0; i<nfood; i++)
    {
        if( f[i].put_time )
        {
            if( !f[i].enable || (time(NULL) - f[i].put_time) > FOOD_EXPIRE_SECONDS )
            {
                putFoodSeed(&f[i]);
            }
        }
    }
    attroff(COLOR_PAIR(3));
}
void initTail(struct tail_t t[], size_t size)
{
    struct tail_t init_t= {0,0};
    for(size_t i=0; i<size; i++)
    {
        t[i]=init_t;
    }
}

void initLives(struct lives_t *lives, int x, int y)
{
    lives->x = x;
    lives->y = y;
    lives->nbr_of_lives = START_LIVES;
 
 
}

void initHead(struct snake_t *head, int x, int y)
{
    head->x = x;
    head->y = y;
    head->direction = RIGHT;
}
//========================================================================
void initSnake(snake_t *head[], size_t size, int x, int y,int l_x, int l_y,int i)
{
    head[i]    = (snake_t*)malloc(sizeof(snake_t));
    lives_t *lives = (lives_t*)malloc(sizeof(lives_t));  
    tail_t*  tail  = (tail_t*) malloc(MAX_TAIL_SIZE*sizeof(tail_t));
    initTail(tail, MAX_TAIL_SIZE);
    initLives(lives, l_x, l_y);
    initHead(head[i], x, y);
    head[i]->tail     = tail; // прикрепляем к голове хвост
    head[i]->tsize    = size+1;
    head[i]->controls = default_controls[i];
    head[i]->lives = lives;
    //~ head[i]->controls = default_controls[0];
}

/*
 Движение головы с учетом текущего направления движения
 */
void go(struct snake_t *head)
{
    char ch = '@';
    int max_x=0, max_y=0;
    getmaxyx(stdscr, max_y, max_x); // macro - размер терминала
    mvprintw(head->y, head->x, " "); // очищаем один символ
    switch (head->direction)
    {
         case LEFT:
            if(head->x <= 0) // Циклическое движение, чтобы не уходить за пределы экрана
                head->x = max_x;
            mvprintw(head->y, --(head->x), "%c", ch);
        break;
        case RIGHT:
            if(head->x >= max_x) 
                head->x = 0;
            mvprintw(head->y, ++(head->x), "%c", ch);
        break;
        case UP:
            if(head->y <= 0) 
                head->y = max_y;
            mvprintw(--(head->y), head->x, "%c", ch);
        break;
        case DOWN:
            if(head->y >= max_y) 
                head->y = 0;
            mvprintw(++(head->y), head->x, "%c", ch);
        break;
        default:
        break;
    }
    refresh();
}

void changeDirection(struct snake_t* snake, const int32_t key)
{
    if (key == snake->controls.down)
        snake->direction = DOWN;
    else if (key == snake->controls.up)
        snake->direction = UP;
    else if (key == snake->controls.right)
        snake->direction = RIGHT;
    else if (key == snake->controls.left)
        snake->direction = LEFT;
}

/*
 Движение хвоста с учетом движения головы
 */
void goTail(struct snake_t *head)
{
    char ch = '*';
    mvprintw(head->tail[head->tsize-1].y, head->tail[head->tsize-1].x, " ");
    for(size_t i = head->tsize-1; i>0; i--)
    {
        head->tail[i] = head->tail[i-1];
        if( head->tail[i].y || head->tail[i].x)
            mvprintw(head->tail[i].y, head->tail[i].x, "%c", ch);
    }
    head->tail[0].x = head->x;
    head->tail[0].y = head->y;
}

//========================================================================
//Проверка того, является ли какое-то из зерен съеденным,
_Bool haveEat(struct snake_t *head, struct food f[])
{
       for(size_t i=0; i<MAX_FOOD_SIZE; i++)
    {
        if( f[i].x == head->x && f[i].y == head->y)
        {
           f[i].enable = 0;
           return 1;
        }
    }
    return 0;
}

/*
 Увеличение хвоста на 1 элемент
 */

void addTail(struct snake_t *head)
{
      if (head->tsize < MAX_TAIL_SIZE) 
      {
        head->tail[head->tsize].x = head->tail[head->tsize - 1].x;
        head->tail[head->tsize].y = head->tail[head->tsize - 1].y;
        head->tsize++;
      }
}
//========================================================================

int checkDirection(struct snake_t* snake,   int32_t key)
{
  for (int i = 0; i < CONTROLS; i++)
   {
    if (key == snake->controls.down && snake->direction == UP)
        return 0;
    else if (key == snake->controls.up && snake->direction == DOWN)
        return 0;
    else if (key == snake->controls.right && snake->direction == LEFT)
        return 0;
    else if (key == snake->controls.left && snake->direction == RIGHT)
        return 0;
    }
  return 1;
}
//========================================================================
void display_lives(struct snake_t *head)
{
	char ch = '#';	
	for (int i = 0; i < START_LIVES; i++)
    {
        mvprintw(head->lives->y, head->lives->x + i, " ");
    }
    for(int i=0; i< head->lives->nbr_of_lives; i++)
    {
      mvprintw(head->lives->y, head->lives->x+i, "%c", ch);
    }
}
//========================================================================
void update(struct snake_t *head, struct food f[], const int32_t key, int snake_index, int nbr_of_plrs)
{
    clock_t begin = clock();    
    if (snake_index == 0)
        attron(COLOR_PAIR(SNAKE1_COLOR));  
    else if (snake_index == 1)
        attron(COLOR_PAIR(SNAKE2_COLOR));  
    go(head);
    goTail(head);
    display_lives(head);
    if (snake_index == 0) 
      attroff(COLOR_PAIR(SNAKE1_COLOR));
    else if (snake_index == 1) 
      attroff(COLOR_PAIR(SNAKE2_COLOR));
    
    if (checkDirection(head,key))
    {
        changeDirection(head, key);
    }
    refreshFood(food, SEED_NUMBER);// Обновляем еду
    if (haveEat(head,food))
    {
        addTail(head);
    }
    mvprintw(1, 10,"Number of lives for snake#1:");
    if (nbr_of_plrs == 2)
         mvprintw(1, 70,"Number of lives for snake#2:");
    refresh();//Обновление экрана, вывели кадр анимации
    while ((double)(clock() - begin)/CLOCKS_PER_SEC<DELAY)
    {}
}
//========================================================================

_Bool isCrush(snake_t * head)
{
        for(size_t i = head->tsize-1; i > 0; i--)
    {
        if(head->tail[i].y == head->y && head->tail[i].x == head->x) 
           return 1;
    }
    return 0;
}
//========================================================================

void repairSeed(struct food f[], size_t nfood, struct snake_t *head)
{
    int max_x=0, max_y=0;
    getmaxyx(stdscr, max_y, max_x); 
    for(size_t i=0; i<head->tsize; i++)
    {
        for(size_t j=0; j<nfood; j++)
        {
            if(f[j].enable && head->tail[i].x == f[j].x && head->tail[i].y == f[j].y)
            {
                f[j].x = rand() % (max_x - 1);
                f[j].y = rand() % (max_y - 2) + 1; 
            }
        }
    }
    for(size_t i=0; i<nfood; i++)
    {
        for(size_t j=i+1; j<nfood; j++) 
        {
            if(f[i].enable && f[j].enable && f[i].x == f[j].x && f[i].y == f[j].y)
            {
                f[j].x = rand() % (max_x - 1);
                f[j].y = rand() % (max_y - 2) + 1; 
            }
        }
    }
}

void display_menu(int *choice) {
    initscr(); 
    noecho(); 
    keypad(stdscr, TRUE); 
    curs_set(FALSE); 
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    attron(COLOR_PAIR(3));
    mvprintw(10, 40,"--------------------\n");
    mvprintw(11, 40,"THIS IS A SNAKE GAME\n");
    mvprintw(12, 40,"--------------------\n");
    attron(COLOR_PAIR(4));
    mvprintw(13, 40,"Make your choice:\n");
    mvprintw(14, 40,"1. One player \n");
    mvprintw(15, 40,"2. Two players\n");
    mvprintw(16, 40,"3. Exit\n");
    mvprintw(17, 40,"Enter the option number: ");
    refresh(); 
    echo(); 
    scanw("%d", choice); 
    noecho(); 
}

int main() {
    int choice;
    int PLAYERS = 1;

    display_menu(&choice); 
    clear(); 
    refresh(); 
    switch (choice) {
        case 1:
            mvprintw(14, 40,"One player selected.\n");
            PLAYERS = 1;
            break;
        case 2:
            mvprintw(14, 40,"Two players selected.\n");
            PLAYERS = 2;
            break;
        case 3:
            mvprintw(14, 40,"Exiting the game.\n");
            refresh();
            sleep(1); 
            endwin();
            return 0;
        default:
            mvprintw(14, 40,"Invalid option number.\n");
            refresh();
            sleep(1); 
            endwin(); 
            return 1;
    }
    refresh();
    sleep(1); 
    clear(); 
    attroff(COLOR_PAIR(1));
    attroff(COLOR_PAIR(2));
    attroff(COLOR_PAIR(3));
    attroff(COLOR_PAIR(4));
 //========================================================================   
snake_t* snakes[PLAYERS];
    for (int i = 0; i < PLAYERS; i++)
        initSnake(snakes,START_TAIL_SIZE,10+i*10,10+i*10,i*60+40,1,i);
//========================================================================
      
    mvprintw(0, 40,"Use arrows for control. Press 'F10' for EXIT");
    timeout(0);    
    
    initFood(food, MAX_FOOD_SIZE);
    putFood(food, SEED_NUMBER);// Кладем зерна
    int key_pressed=0;
    int game_over = 0; 
    int max_x = 0, max_y = 0;
    while( key_pressed != STOP_GAME && game_over != 1 )
    {
		getmaxyx(stdscr, max_y, max_x); // macro - размер терминала
        key_pressed = getch(); // Считываем клавишу
        for (int i = 0; i < PLAYERS; i++)
        {
            update(snakes[i], food, key_pressed,i,PLAYERS);
            if(isCrush(snakes[i]))
            {
			  snakes[i]->lives->nbr_of_lives--;
			  if ( snakes[i]->lives->nbr_of_lives<=0)
			  {
			   clear();
			   setColor(1);
			   mvprintw(max_y / 2, max_x / 2, "GAME OVER");
               refresh();
               sleep(2);
               game_over = 1;
               break;
              }
            }
            repairSeed(food, SEED_NUMBER, snakes[i]);
        }
    }
    for (int i = 0; i < PLAYERS; i++)
    {
        free(snakes[i]->tail);
        free(snakes[i]->lives);
        free(snakes[i]);
    }
    endwin(); 
    return 0;
}
