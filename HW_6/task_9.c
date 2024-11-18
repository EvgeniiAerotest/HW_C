/* HW5
 * task_9.c
 *
 */
 
int factorial(int n);

#include <stdio.h>
int main(void)
{
 int n; 
 scanf ("%d", &n);	  
 printf("%d ",factorial(n));
 return 0;  
}


int factorial(int n)
{
  int factorial=1;	
  for (int i=1; i<=n; i++)
  {
	  factorial = factorial*i;
  }
  return factorial;
}

