/* HW5
 * task_7.c
 *
 */
#include <stdio.h>
int main(void)
{
	int a, dig;
	int counter_0 = 0;
	int counter_1 = 0;
	int counter_2 = 0;
	int counter_3 = 0;
	int counter_4 = 0;
	int counter_5 = 0;
	int counter_6 = 0;
	int counter_7 = 0;
	int counter_8 = 0;
	int counter_9 = 0;
	scanf("%d", &a);
	while (a != 0)
	{
		
		dig = a % 10;
		a = a / 10;
		switch(dig)
		{			
			case 0:
			counter_0++;
			break;
			case 1:
			counter_1++;
			break;
			case 2:
			counter_2++;
			break;
			case 3:
			counter_3++;
			break;
			case 4:
			counter_4++;
			break;
			case 5:
			counter_5++;
			break;
			case 6:
			counter_6++;
			break;
			case 7:
			counter_7++;
			break;
			case 8:
			counter_8++;
			break;
			case 9:
			counter_9++;
			break;
		}
	}
	if    ((counter_0>1)
	     ||(counter_1>1)
	     ||(counter_2>1)
	     ||(counter_3>1)
	     ||(counter_4>1)
	     ||(counter_5>1)
	     ||(counter_6>1)
	     ||(counter_7>1)
	     ||(counter_8>1)
	     ||(counter_9>1))
	{
		printf("YES");
	}
	else 
	{
		printf("NO");
	}
	return 0;
}
