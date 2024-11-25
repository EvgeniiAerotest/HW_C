/* HW7
 * task_4.c
 *
 */
#include <stdio.h>
 
void DigRec(int n);

int main(void)
{
 int n;
 scanf("%d", &n);
 if (n>0)
   DigRec(n);
 else
   printf("%d ",n);
 return 0;
}

void DigRec(int n)
{
 if(n>0)
 {
  static int p=1;	
  DigRec(n / 10);
  p = n%10;
  printf("%d ",p);
 }	 
}
