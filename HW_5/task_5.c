/* HW5
 * task_5.c
 *
 */
#include <stdio.h>
int main(void)
{
	int a, dig;
	int sum = 0;
	int i = 0;
	int arr[100];
	scanf("%d", &a);
	while (a != 0)
	{
		dig = a % 10;
		arr[i] = dig;
		i++;
		a = a / 10;
	}
	for (int k = 0; k < i; k++)
	{
		sum += arr[k];
	}
	printf("%d", sum);
	return 0;
}
