/* HW6
 * task_1.c
 *
 */

#include <stdio.h>
 
int abs (int a);

int main(void)
{
	int a;
	scanf("%d", &a);
    printf("%d", abs(a));
}


int abs (int a)
{
	if (a<0)
		return (a*-1);
	else 
		return (a);
}
