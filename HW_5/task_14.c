/* HW5
 * task_14.c
 */
#include <stdio.h>
int a=1;
int counter=0;
int main(void)
{
 while(a!=0)
 {
	scanf("%d", &a);
	if (a != 0)
	{
	counter++;	
	}	
 } 
printf("%d\n",counter);
return 0;
}
