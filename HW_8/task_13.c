
/*
 *  HW8
 * task_13.c
 *
 */

#include <stdio.h>

#define SIZE 10
 
int Input(int len, int* arr);
void Print(int len, int *arr);
void Sort_2d0(int len,int *arr);

int main(void)
{
 int arr[SIZE]={0};
 Input(SIZE, arr); 
 Sort_2d0(SIZE,arr);	
 return 0;
}

int Input(int len, int* arr) 
{
 int i;
 for(i=0;i<len;i++)
   scanf("%d",&arr[i]);
 return i;
}

void Print(int len, int *arr)
{
 int i;  
 for (i = 0; i < len; i++)
    printf("%d ",arr[i]);
 printf("\n");
}

void Sort_2d0(int len,int *arr)
{
  int temp_arr[10] = {0};
  int count=0;
  for (int i=0; i<len; i++)
  {
    if ((arr[i]/10)%10 == 0)
    {
      temp_arr[count] = arr[i];
      count++; 
    }
  }
  int result_arr[count];
  for(int i=0; i<count; i++)
      result_arr[i] = temp_arr[i];
  Print(count, result_arr);  
}
