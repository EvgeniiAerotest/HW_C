/*
 *  HW9
 * task_7.c
 *
 */

#include <stdio.h>

#define SIZE 10

int Input(int len, int *arr);
void Print(int len, int *arr);
int compression(int a[], int b[], int N);

int main(void)
{
	int a[SIZE], b[SIZE], len;
	Input(SIZE, a);
	len = compression(a, b, SIZE);
	Print(len, b);
	return 0;
}

int Input(int len, int *arr)
{
	int i;
	for (i = 0; i < len; i++)
		scanf("%d", &arr[i]);
	return i;
}

void Print(int len, int *arr)
{
	int i;
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
}

int compression(int a[], int b[], int N)
{
	int counter_0 = 0, counter_1 = 0, counter_p = 0;
	int flag_0 = 0, flag_1 = 0;
	for (int i = 0; i < N; i++)
	{
		if (a[i] == 0)
		{
			if (flag_0 == 0 && counter_p > 0)
			{
				flag_0 = 1;
				flag_1 = 0;
				b[counter_p] = counter_1;
				counter_p++;
				counter_1 = 0;
			}
			counter_0++;
			if (i == N - 1)
				b[counter_p] = counter_0;
		}
		else if (a[i] == 1)
		{
			if (flag_1 == 0)
			{
				flag_1 = 1;
				flag_0 = 0;
				b[counter_p] = counter_0;
				counter_p++;
				counter_0 = 0;
			}
			counter_1++;
			if (i == N - 1)
				b[counter_p] = counter_1;
		}
	}
	return counter_p + 1;
}
