
#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

typedef float(*function)(float);

float f1(float x)            
{  
  return  0.6*x + 3;  // f1=0.6x+3 
}

float f2(float x)           
{  
  return   x*x*x - 6*x*x + 12*x - 9; // f2=(x-2)^3 - 1
}


float f3(float x)
{   
  return 3/x;     // f3=3/x
}

float f1_f2(float x) 
{   
  return x*x*x - 6*x*x + 11.4*x - 12;  // f1=f2=x^3-6x^2+11.4x-12
}

float f2_f3(float x) 
{
  return x*x*x*x - 6*x*x*x + 12*x*x - 9*x - 3;  // f2=f3=x^4-6x^3+12x^2-9x-3
}

float f1_f3(float x) { 
  return 0.6*x*x + 3*x - 3;   //f1=f3=0.6x^2+3x-3
}


float test_f1(float x)   // тестовая функция для проверки поиска корней уравнений
{  
  return  sin(x);
}

float test_f2(float x) // тестовая функция для проверки расчета интегралов
{  
  return  2;
}


float rootFindChord(float xl, float xr, float eps, function f, int p_mode) {
    int stepcount=0; 
    while(fabs(xr - xl) > eps) {
        xl = xr - (xr - xl) * f(xr) / (f(xr) - f(xl));
        xr = xl - (xl - xr) * f(xl) / (f(xl) - f(xr));
        stepcount++;
    }
    if (p_mode)
      printf("Find Chord Search root for %d steps\n",stepcount);
    return xr;
}

float calcIntegralSimpson(float xl, float xr, size_t n, function f) {
    float sum = 0;
    float h = (xr-xl)/n;
    for(float x=xl+h; x<xr-h; x+=h) {
        sum += h/6.0*(f(x) + 4.0*f(0.5*(x+x+h)) + f(x+h));
    }
    return sum;
}


void print_help(void)
{
	printf("This is description of this application usage:\n");
    printf("-h: this help text;\n");
    printf("-t: test mode enable;\n");
    printf("-r: print roots x coords;\n");
    printf("-s: print number of steps;\n");
}


/*  
 * Функция test:
 * 1. Тестирует функцию rootFindChord  
 *    В качестве тестового уравнения используется ф-я f=sin(x) 
 *    пользователю предлагается ввести граничные условия для поиска корня функции sin(x)
 *    например при вводе граничных условий 3, 3.5, функция должна вернуть пи (3.14),
 *    при вводе граничных условий 6, 6.5, функция должна вернуть 2*пи и.т.д.
 * 2. Тестирует функцию calcIntegralSimpson
 *    В качестве тестового уравнения используется ф-я f=2
 *    пользователю предлагается ввести пределы интегрирования 
 *    функция возвращает результат интегрирования с заданными пределами 
*/
void test(void)
{
    float lx,rx,lix,rix; // граничные условия для тестовых функций
    printf("This is test for equations solving\n");      
	printf("Test function: f=sin(x)\n");                
	printf("Enter left x(from 0 to 100): ");           
    scanf("%f", &lx);                                    
    printf("Enter right x(from 0 to 100): ");            
    scanf("%f", &rx);                                    
    printf("test r = %f\n", rootFindChord(lx,rx,0.001,test_f1,1)); 
       
    printf("                                     \n");
    printf("This is test for integral calculation\n");
	printf("Test function: f=2\n");
	printf("Enter left x(from 0 to 100): ");
    scanf("%f", &lix); 
    printf("Enter right x(from 0 to 100): ");
    scanf("%f", &rix);  
    printf("test s = %f\n", calcIntegralSimpson(lix,rix,1000,test_f2)); 
}

int main(int argc, char **argv) {
	
	float eps1, eps2;    // точность вычисления корней уравнения и интегралов
	int rez = 0;         // сюда возвращает значение функция обработки аргументов командной строки
	int p_mode=0,help_mode=0,test_mode=0,p_roots_mode=0; //Флаги режимов работы программы. Они выставляются в зависимости от аргументов,  
	                                                     //введенных из командной строки 
   while ((rez = getopt(argc, argv, "hsrt")) != -1)
  {
    switch (rez)        //Обработка аргументов командной строки
    {
    case 'h':
      help_mode=1;      //Выбран режим "Помощь"
      break;
    case 's':
      p_mode = 1;       //Выбран режим "Печать количества итераций"
      p_roots_mode = 1; //Если выбран данный режим корни уравнений тоже печатаем
      break;
    case 'r':
      p_roots_mode = 1; //Выбран режим "Печать координат точечек пересечения кривых"  
      break;
    case 't':
      test_mode = 1;    //Выбран режим "Тест"
      break;
    case '?':
      printf("Error found !\n");
      break;
    };
  };
	
	if (help_mode)      // Рехим "Помощь"
	  print_help();     
	else if (test_mode) // Режим "Тест"  
	  test(); 
	else 
	{
	  printf("Enter the precision (eps1) for roots calculations (from 0.1 to 0.0001): ");  // Пользователь вводит желаемую точность 
      scanf("%f", &eps1);                                                                  // вычисления корней уравнений
      printf("Enter the precision (eps2) for integral calculations (from 10 to 10000): "); // Пользователь вводит желаемую точность 
      scanf("%f", &eps2);                                                                  // вычисления определенного интеграла
      float r1 = rootFindChord(-6,5.5,eps1,f1_f3,p_mode);     // Находим корни
      float r2 = rootFindChord(-0.5,0,eps1,f2_f3,p_mode);     // Если выбран режим "Печать количества итераций" (p_mode=1)
      float r3 = rootFindChord(0.5,1,eps1,f1_f3,p_mode);      // Печатаем stepcount
      float r4 = rootFindChord(3,3.5,eps1,f2_f3,p_mode);      
      float r5 = rootFindChord(3.5,4,eps1,f1_f2,p_mode);      
      float x1 = rootFindChord(-4.5,-5.5,eps1,f1,0);
      float x2 = rootFindChord(2.5,3.5,eps1,f2,0);     
      if (p_roots_mode) // Если выбран режим "Печать координат точечек пересечения кривых" 
      {
	     printf("Root r1 = %f\n", r1);   // Печатаем абсциссы точек пересечения кривых
	     printf("Root r2 = %f\n", r2);
	     printf("Root r3 = %f\n", r3);
	     printf("Root r4 = %f\n", r4);
	     printf("Root r5 = %f\n", r5);	  
	  }     
      printf("Square = %f\n",fabsf(calcIntegralSimpson(r1,r2,eps2,f3))+  // Вычисляем и печатаем площадь фигуры, образованной
                             fabsf(calcIntegralSimpson(r2,x2,eps2,f2))+  // пересечением трех функций. 
                             fabsf(calcIntegralSimpson(x1,r5,eps2,f1))-
                             fabsf(calcIntegralSimpson(r1,x1,eps2,f1))-
                             fabsf(calcIntegralSimpson(x2,r5,eps2,f2))); 
    }                                     
     
    return 0;    
}
