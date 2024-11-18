/* HW5
 * task_3.c
 *
 */
 
#include <stdio.h> 
 
int midle (int n, int p);

int main(void)
{
	int n,p;
	scanf("%d%d",&n ,&p);
    printf("%d", midle(n,p));
}


int midle (int n, int p)
{
  int midle;
  midle = (n+p)/2;
  return(midle);
}
