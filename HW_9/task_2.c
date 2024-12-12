/*
 *  HW10
 * task_2.c
 *
 */

#include <stdio.h>

#define SIZE 20

int Input(int len, int *arr);
void sort_even_odd(int n, int a[]);

int main(void)
{
   int arr[SIZE] = {0};
   Input(SIZE, arr);
   sort_even_odd(SIZE, arr);
   return 0;
}

int Input(int len, int *arr)
{
   int i;
   for (i = 0; i < len; i++)
      scanf("%d", &arr[i]);
   return i;
}

void sort_even_odd(int n, int a[])
{
   int even_arr[n];
   int odd_arr[n];
   int even_count = 0;
   int odd_count = 0;
   int temp_count = 0;
   for (int i = 0; i < n; i++)
   {
      if (a[i] % 2 == 0)
      {
         even_arr[even_count] = a[i];
         even_count++;
      }
      else
      {
         odd_arr[odd_count] = a[i];
         odd_count++;
      }
   }

   temp_count = even_count;

   for (int i = 0; i < even_count; i++)
      a[i] = even_arr[i];
   for (int i = 0; i < n - even_count; i++)
   {
      a[temp_count] = odd_arr[i];
      temp_count++;
   }
   for (int i = 0; i < n; i++)
      printf("%d ", a[i]);
}
