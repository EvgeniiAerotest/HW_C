/* HW5
 * task_17.c
*/ 
#include <stdio.h>
int main(void)
{
	int a, b, dig;
	int sum = 0;
	int mul = 1;
	scanf("%d", &a);
	for (int i=10; i<=a; i++)
	{
	  b=i;
	  while (b != 0)
	  {
		dig = b % 10;
		sum += dig;
		mul *= dig; 
		b = b / 10;
	  }
	  if (sum==mul)
		printf("%d ", i);
	  sum = 0;
	  mul = 1;	
	}
	return 0;
}


