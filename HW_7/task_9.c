/* HW7
 * task_9.c
 *
 */

#include <stdio.h>
 
int SumRec(int a);

int main(void)
{
 int a;
 scanf("%d",&a);   
 printf("%d", SumRec(a));   
}

int SumRec(int num)
{
 if (num > 0)
   return num % 10 + SumRec(num / 10);
 else
   return 0;
} 
 

