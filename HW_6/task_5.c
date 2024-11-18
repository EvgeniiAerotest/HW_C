/* HW6
 * task_5.c
 *
 */
#include <stdio.h>
 
void sum (int n);


int main(void)
{
 int n;
 scanf("%d", &n);   
 sum(n);  
}


void sum(int n)
{
  int sum=0;
  for (int i=1; i<=n; i++)
  {
	sum+=i;  
  }
   printf("%d", sum);
}
