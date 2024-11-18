/* HW6
 * task_4.c
 *
 */

#include <stdio.h>
 
int fcalc (int x);

int main(void)
{
 int a=1;
 int t;
 int max=-2147483648;		   
 while(a!=0)
 {  
   scanf("%d", &a);
   if (a!=0)
   {
      t = fcalc(a);
      if (t > max)
		max=t;
   }
 }
 printf("%d\n",max);   
}


int fcalc (int x)
{
  int f=0;
  if ((x>=-2)&&(x<2))
  {
	f = x*x;
  }
  else if (x>=2)
  {
	f = x*x+4*x+5; 
  }
  else if (x<-2)
  {
	f = 4;	
  } 
  return(f);
}
