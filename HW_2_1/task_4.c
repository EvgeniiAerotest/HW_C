/* HW2_1
 * task_4.c
 *
 *
 */

#include <stdio.h>
#include <stdint.h>

unsigned int Max_bits(uint32_t n, uint32_t k)
{
	int max = 0;
	int temp;
	for (int i = 0; i < (32 - (k - 1)); i++)
	{
		temp = ((1 << k) - 1) & n;
		if (temp > max)
			max = temp;
		n = n >> 1;
	}
	return max;
}
int main(void)
{

	uint32_t n, k, res;
	scanf("%d %d", &n, &k);
	res = Max_bits(n, k);
	printf("%u", res);

	return 0;
}
