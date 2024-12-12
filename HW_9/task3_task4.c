/*
 *  HW9
 * task_3&task_4.c
 *
 */

#include <stdio.h>

#define SIZE 20

void print_digit(char s[]);

int main(void)
{
  char s[1000], c;
  int i = 0;

  while ((c = getchar()) != '\n')
    s[i++] = c;
  s[i] = '\0';

  print_digit(s);
  return 0;
}

void print_digit(char s[])
{
  int arr_count[10] = {0};
  int k = 0;

  while (s[k]) 
  {
    switch (s[k])
    {
    case '0':
      arr_count[0]++;
      break;
    case '1':
      arr_count[1]++;
      break;
    case '2':
      arr_count[2]++;
      break;
    case '3':
      arr_count[3]++;
      break;
    case '4':
      arr_count[4]++;
      break;
    case '5':
      arr_count[5]++;
      break;
    case '6':
      arr_count[6]++;
      break;
    case '7':
      arr_count[7]++;
      break;
    case '8':
      arr_count[8]++;
      break;
    case '9':
      arr_count[9]++;
      break;
    }
    k++;
  }
  for (int i = 0; i < 10; i++)
  {
    if (arr_count[i] != 0)
      printf("%d %d\n", i, arr_count[i]);
  }
}
