/* HW5
 * task_15.c
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
	 if ((a % 2)==0)
		counter++;	
	}	
 } 
printf("%d\n",counter);
return 0;
}
