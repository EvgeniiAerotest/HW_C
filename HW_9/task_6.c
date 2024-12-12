/*
 *  HW9
 * task_6.c
 *
 */

#include <stdio.h>

#define SIZE 5

int Input(int len, int *arr);
int is_two_same(int size, int a[]);

int main(void)
{
  int arr[SIZE];
  Input(SIZE, arr);
  printf("%s", (is_two_same(SIZE, arr)) ? "YES" : "NO");
  return 0;
}

int Input(int len, int *arr)
{
  int i;
  for (i = 0; i < len; i++)
    scanf("%d", &arr[i]);
  return i;
}

int is_two_same(int size, int a[])
{
  int s_flag = 0;
  int temp;

  for (int i = 0; i < size; i++)
  {
    for (int j = size - 1; j > i; j--)
    {
      if (a[j - 1] > a[j])
      {
        temp = a[j - 1];
        a[j - 1] = a[j];
        a[j] = temp;
      }
    }
  }

  for (int i = 0; i < size - 1; i++)
  {
    if (a[i] == a[i + 1])
      s_flag = 1;
  }

  return s_flag;
}
