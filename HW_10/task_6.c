/*
 *  HW10
 * task_6.c
 *
 */

#include <stdio.h>
#include <string.h>

#define SIZE 1000

int is_palindrom(char *str);
void save_str_to_file(char *filename, char *str);
int load_f(char *filename, char *str);

int main(void)
{
  char s[SIZE];

  load_f("input.txt", s);
  if (is_palindrom(s))
    save_str_to_file("output.txt", "YES");
  else
    save_str_to_file("output.txt", "NO");

  return 0;
}

int is_palindrom(char *str)
{
  int f = 1;
  int len = strlen(str);

  for (int i = 0; i < ((len) / 2); i++)
  {
    if (str[i] != str[len - 1 - i])
    {
      f = 0;
      break;
    }
  }
  return f;
}

int load_f(char *filename, char *str)
{
  FILE *f;
  f = fopen(filename, "r");
  fscanf(f, "%[^\n]", str);
  fclose(f);
  return strlen(str);
}

void save_str_to_file(char *filename, char *str)
{
  FILE *f;
  f = fopen(filename, "w");
  fprintf(f, str);
  fclose(f);
}
