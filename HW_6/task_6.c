/* HW6
 * task_6.c
 *
 */

#include <stdio.h>
 
void expon (int n);

int main(void)
{
 int n;
 scanf("%d", &n);   
 expon(n);  
}


void expon(int n)
{
  unsigned long long int expon=1;
  for (int i=1; i<n; i++)
  {
	expon=expon*2;  
  }
   printf("%llu", expon);
}
