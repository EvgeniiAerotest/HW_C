/*
 *  HW10
 * task_7.c
 *
 */

#include <stdio.h>
#include <string.h>

#define SIZE 10000

int load_f(char *filename, char *str);
void save_f(char *filename, char *str, int *s_l_count, int *b_l_count);
void lett_count(int len, char *str, int *s_l_count, int *b_l_count);

int main(void)
{
  char s[SIZE];
  int s_l_count = 0;
  int b_l_count = 0;

  int len = load_f("input.txt", s);
  lett_count(len, s, &s_l_count, &b_l_count);
  save_f("output.txt", s, &s_l_count, &b_l_count);

  return 0;
}

void lett_count(int len, char *str, int *s_l_count, int *b_l_count)
{

  for (int i = 0; i < len; i++)
  {
    if (str[i] >= 'a' && str[i] <= 'z')
      (*s_l_count)++;
    else if (str[i] >= 'A' && str[i] <= 'Z')
      (*b_l_count)++;
  }
}

int load_f(char *filename, char *str)
{
  FILE *f;
  f = fopen(filename, "r");
  fscanf(f, "%[^\n]", str);
  fclose(f);
  return strlen(str);
}

void save_f(char *filename, char *str, int *s_l_count, int *b_l_count)
{
  FILE *f;
  f = fopen(filename, "w");
  fprintf(f, "%d %d", *s_l_count, *b_l_count);
  fclose(f);
}
