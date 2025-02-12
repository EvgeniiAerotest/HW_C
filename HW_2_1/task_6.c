/* HW2_1
 * task_6.c
 *
 *
 */

#include <stdio.h>
#include <stdint.h>

unsigned int invert_high_byte(uint32_t n)
{

	return n ^ 0xFF000000;
}

int main(void)
{
	uint32_t n, res;
	scanf("%d", &n);
	res = invert_high_byte(n);
	printf("%u", res);

	return 0;
}
