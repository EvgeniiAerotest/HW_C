/* HW6
 * task_2.c
 *
 */
 
#include <stdio.h> 
 
int expon (int n, int p);

int main(void)
{
	int n,p;
	scanf("%d%d",&n ,&p);
    printf("%d", expon(n,p));
}


int expon (int n, int p)
{
  int mult=1;
  for (int i = 1; i <= p; i++)
  {
	  mult*=n;
  }
  return(mult);
}
