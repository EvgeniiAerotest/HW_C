/* HW5
 * task_6.c
 *
 */
#include <stdio.h>
int main(void)
{
	int a, dig, dig_prev;
	int flag = 0;
	scanf("%d", &a);
	while (a != 0)
	{
		dig = a % 10;
	    if (dig==dig_prev)
	    {
			flag = 1;
		}
		dig_prev = dig;
		a = a / 10;
	}
	if (flag == 1)
	{
		printf("YES");
	}
	else 
	{
		printf("NO");
	}
	return 0;
}
