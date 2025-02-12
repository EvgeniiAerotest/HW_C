
/* HW2_1
 * task_2.c
 *
 *
 */

#include <stdio.h>
#include <stdint.h>

unsigned int rightRotate(uint32_t n, uint32_t rotate)
{
	return (n >> rotate) | (n << (32 - rotate));
}
int main()
{
	uint32_t a, rotate, res;

	scanf("%d %d", &a, &rotate);
	res = rightRotate(a, rotate);
	printf("%u", res);

	return 0;
}
