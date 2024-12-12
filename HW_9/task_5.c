/*
 *  HW9
 * task_5.c
 *
 */

#include <stdio.h>

#define SIZE 5

int Input(int len, int *arr);
int find_max_array(int size, int a[]);

int main(void)
{
  int arr[SIZE];
  Input(SIZE, arr);
  printf("%d ", find_max_array(SIZE, arr));
  return 0;
}

int Input(int len, int *arr)
{
  int i;
  for (i = 0; i < len; i++)
    scanf("%d", &arr[i]);
  return i;
}

int find_max_array(int size, int a[])
{
  int max = a[0];
  for (int i = 1; i < size; i++)
  {
    if (a[i] > max)
      max = a[i];
  }
  return max;
}
