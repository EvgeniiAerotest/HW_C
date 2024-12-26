/*
 *  HW10
 * task_3.c
 *
 */

#include <stdio.h>
#include <string.h>

#define SIZE 100

int main(void)
{

	char s[SIZE];
	char lastc;
	int count = 0;
	int result[100];

	FILE *f;
	f = fopen("input.txt", "r");
	fscanf(f, "%[^\n]", s);
	fclose(f);
	int len = strlen(s);
	lastc = s[len - 1];
	for (int i = 0; i < len - 1; i++)
	{
		if (s[i] == lastc)
		{

			result[count] = i;
			count++;
		}
	}

	f = fopen("output.txt", "w");
	for (int i = 0; i < count; i++)
		fprintf(f, "%d ", result[i]);
	fclose(f);

	return 0;
}
