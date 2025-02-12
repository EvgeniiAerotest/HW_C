/* HW2_1
 * task_3.c
 *
 *
 */

#include <stdio.h>
#include <stdint.h>

unsigned int takeBits(uint32_t n, uint32_t k)
{
	return ((1 << k) - 1) & n;
}
int main(void)
{

	uint32_t n, k, res;
	scanf("%d %d", &n, &k);
	res = takeBits(n, k);
	printf("%u", res);

	return 0;
}
