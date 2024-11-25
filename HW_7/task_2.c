/* HW7
 * task_2.c
 *
 */
 
int SumRec(int n);

#include <stdio.h>
int main(void)
{
 int n;
 scanf("%d", &n);
 printf("%d ", SumRec(n));
 return 0;
}

int SumRec(int n)
{
 if(n>0)
   n = n+SumRec(n-1);
 return n;
}
