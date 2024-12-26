/*
 *  HW10
 * task_8.c
 *
 */

#include <stdio.h>
#include <string.h>

#define SIZE 1000

int load_f(char *filename, char *str);
void save_f(char *filename, int *n, int count);
void SwapArr(int i, int j, int *arr);
void Sort(int len, int *arr);
int num_sort(char *str, int *n);

int main(void)
{

  int count = 0;
  char s[SIZE];
  int n[SIZE];

  load_f("input.txt", s);
  count = num_sort(s, n);
  Sort(count, n);
  save_f("output.txt", n, count);

  return 0;
}

int num_sort(char *str, int *n)
{

  int count = 0;
  int num = 0;
  int num_flag = 0;
  int len = strlen(str);
  for (int i = 0; i < len; i++)
  {
    if (str[i] >= '0' && str[i] <= '9')
    {
      num = num * 10 + (str[i] - 0x30);
      num_flag = 1;
      if (i == len - 1)
        n[count++] = num;
    }
    else if (num_flag == 1)
    {
      num_flag = 0;
      n[count++] = num;
      num = 0;
    }
  }

  return count;
}

void SwapArr(int i, int j, int *arr)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void Sort(int len, int *arr)
{
  for (int i = 0; i < len; i++)
  {
    for (int j = len - 1; j > i; j--)
    {
      if (arr[j - 1] > arr[j])
      {
        SwapArr(j - 1, j, arr);
      }
    }
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

void save_f(char *filename, int *n, int count)
{
  FILE *f;
  f = fopen("output.txt", "w");
  for (int i = 0; i < count; i++)
    fprintf(f, "%d ", n[i]);
  fclose(f);
}
