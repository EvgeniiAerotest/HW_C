/*
 *  HW8
 * task_15.c
 *
 */

#include <stdio.h>

#define SIZE 5

int Input(int len, int *arr);
void Print(int len, int *arr);
void sort_array(int size, int a[]);

int main(void)
{
  int arr[SIZE] = {0};
  Input(SIZE, arr);
  sort_array(SIZE, arr);
  Print(SIZE, arr);
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

void sort_array(int size, int a[])
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
}
