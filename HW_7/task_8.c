/* HW7
 * task_8.c
 *
 */

#include <stdio.h>

#define UP 1
#define DOWN 0 
 
void ABPrintRec(int a, int b, int dir);

int main(void)
{
 int a,b;
 scanf("%d%d",&a ,&b);   
 if (a<b)
   ABPrintRec(a,b,UP);
 else
   ABPrintRec(a,b,DOWN);    
}


void ABPrintRec(int a, int b, int dir)
{
 switch(dir)
 {
  case UP: 	 
    if (b >= a)
    {
      ABPrintRec(a,b-1,UP);
      printf("%d ", b);   	    
    }
  break;
  
  case DOWN: 	 
    if (a >= b)
    {
      printf("%d ", a);
	  ABPrintRec(a-1,b,DOWN);           	    
    }
  break;
 }
}
