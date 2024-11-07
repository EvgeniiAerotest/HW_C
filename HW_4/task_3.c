/* HW4
 * task_3.c
 *  
 */


#include <stdio.h> 
int main(void)
{
 int a, b, c, max, ch; 
  scanf("%d", &ch); 
  a = (ch/100)%10; // первая цифра числа 
  b = (ch/10)%10;  // вторая цифра числа 
  c = ch%10;       // третья цифра цисла
  max =  a > b ?  a : b;
  max = max> c ? max: c;
  printf("%d\n", max);
 return 0; 
}


 
	
