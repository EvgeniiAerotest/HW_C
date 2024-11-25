/* HW7
 * task_7.c
 *
 */

#include <stdio.h>
 
void NPrintRec(int num);

int main(void)
{
 int n;
 scanf("%d", &n);   
 NPrintRec(n);   
}

void NPrintRec(int num)
{
 if (num > 0)
 {
   printf("%d ", num); 
   NPrintRec(num-1);   
 }
}
