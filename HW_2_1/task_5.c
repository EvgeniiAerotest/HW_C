/* HW2_1
 * task_5.c
 *
 *
 */

#include <stdio.h>
#include <stdint.h>

unsigned int One_counter(uint32_t n)
{
	int count;
	for (int i = 0; i < 32; i++)
	{
		if ((n >> i) & 1)
			count++;
	}
	return count;
}
int main(void)
{

	uint32_t n, res;
	scanf("%d", &n);
	res = One_counter(n);
	printf("%u", res);

	return 0;
}
