/* HW5
 * task_8.c
 */
#include <stdio.h>
int main(void)
{
	int a, dig;
	int counter = 0;
	scanf("%d", &a);
	while (a != 0)
	{
		dig = a % 10;
	    if (dig==9)
	    {
			counter++;
		}
		a = a / 10;
	}
	if (counter == 1)
	{
		printf("YES");
	}
	else 
	{
		printf("NO");
	}
	return 0;
}
