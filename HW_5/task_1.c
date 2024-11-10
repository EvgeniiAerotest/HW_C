/* HW5
 * task_1.c
 *
 */

#include <stdio.h>
int main(void)
{
	int a, squ, cube;
	scanf("%d", &a);
	for (int i = 1; i <= a; i++)
	{
		squ = i * i;
		cube = i * i * i;
		printf("%d %d %d\n", i, squ, cube);
	}
	return 0;
}
