/* HW6
 * task_10.c
 *
 */
 
#include <stdio.h>
 
void print_simple(int n);

int main(void)
{
 int n; 
 scanf ("%d", &n);	  
 print_simple(n);
 return 0;  
}


void print_simple(int n)
{
  int i=2;	
  while (n!=1)
  {
	if(n%i != 0)
	   i++;
	else
	{ 
	   printf("%d ",i);
	   n = n/i;
	}
  }
}

