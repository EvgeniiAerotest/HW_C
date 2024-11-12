/* HW5
 * task_5.c
 *
 */
#include <stdio.h>
int main(void)
{
	int a, dig;
	int sum = 0;
	scanf("%d", &a);
	while (a != 0)
	{
		dig = a % 10;
		sum += dig;
		a = a / 10;
	}
	printf("%d", sum);
	return 0;
}
