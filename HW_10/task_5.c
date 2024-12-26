/*
 *  HW10
 * task_5.c
 *
 */

#include <stdio.h>
#include <string.h>

#define SIZE 1000

int load_f(char *filename, char *str);
void save_f(char *filename, char *str);
void change_ab(char *s, int len);

int main(void)
{
	char s[SIZE];

	int len = load_f("input.txt", s);
	change_ab(s, len);
	save_f("output.txt", s);

	return 0;
}

int load_f(char *filename, char *str)
{
	FILE *f;
	f = fopen(filename, "r");
	fscanf(f, "%[^\n]", str);
	fclose(f);
	return strlen(str);
}

void save_f(char *filename, char *str)
{
	FILE *f;
	f = fopen(filename, "w");
	fprintf(f, "%s ", str);
	fclose(f);
}

void change_ab(char *s, int len)
{
	for (int i = 0; i < len; i++)
	{
		switch (s[i])
		{
		case 'A':
			s[i] = 'B';
			break;
		case 'a':
			s[i] = 'b';
			break;
		case 'B':
			s[i] = 'A';
			break;
		case 'b':
			s[i] = 'a';
			break;
		}
	}
}
