/*
 *  HW9
 * task_8.c
 *
 */

#include <stdio.h>

#define SIZE 1000

int Input(int *arr);
int missed_digit(int size, int a[]);
void Print(int len, int *arr);

int main(void)
{
  int arr[SIZE];
  int len;

  len = Input(arr);
  printf("%d", missed_digit(len, arr));

  return 0;
}

int Input(int *arr)
{
  int i = 0;
  int a;

  scanf("%d", &a);
  while (a != 0)
  {
    arr[i++] = a;
    scanf("%d", &a);
  }
  return i;
}

void Print(int len, int *arr)
{
  int i;
  for (i = 0; i < len; i++)
    printf("%d ", arr[i]);
}

int missed_digit(int size, int a[])
{
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
    if (a[i + 1] - a[i] >= 2)
      return a[i] + 1;
  }

  return 0;
}
