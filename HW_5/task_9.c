/* HW5
 * task_9.c
 */
#include <stdio.h>
int main(void)
{
	int a, dig;
	int odd_flag=0;
	scanf("%d", &a);
	while (a != 0)
	{
		dig = a % 10;
	    if ((dig%2)!=0)
	    {
			printf("NO");
			odd_flag=1;
			break;
		}
		a = a / 10;
	}
    if (odd_flag==0)
		printf("YES");
	return 0;
}
