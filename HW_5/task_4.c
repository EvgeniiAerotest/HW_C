/* HW5
 * task_4.c
 *
 */

#include <stdio.h>
int main(void)
{
	int a, counter;
	scanf("%d", &a);
	while (a != 0)
	{
		a /= 10;
		counter++;
	}
	if (counter == 3)
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}
	return 0;
}
