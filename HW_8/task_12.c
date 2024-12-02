/*
 *  HW8
 * task_11.c
 *
 */

#include <stdio.h>

#define SIZE 10
 
int Input(int len, int* arr);
void Print(int len, int *arr);
void SwapArr(int i,int j,int *arr);
void Sort_half(int len,int *arr);

int main(void)
{
 int arr[SIZE]={0};
 Input(SIZE, arr);
 Sort_half(SIZE,arr);
 Print(SIZE, arr); 	
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

void SwapArr(int i,int j,int *arr)
{
 int temp = arr[i];
 arr[i]   = arr[j];
 arr[j]   = temp;
}


void Sort(int len,int *arr)
{
 for (int i = 0; i < len; i++)
 {
  for (int j = len-1; j > i; j--)
  {
   if(arr[j-1]>arr[j])
   {
    SwapArr(j-1,j,arr);
   }
  }
 }
}

void Sort_ld(int len,int *arr)
{
 for (int i = 0; i < len; i++)
 {
  for (int j = len-1; j > i; j--)
  {
   if((arr[j-1]%10)>(arr[j]%10))
   {
    SwapArr(j-1,j,arr);
   }
  }
 }
}

void Sort_dec(int len,int *arr)
{
 for (int i = 0; i < len; i++)
 {
  for (int j = len-1; j > i; j--)
  {
   if(arr[j-1]<arr[j])
   {
    SwapArr(j-1,j,arr);
   }
  }
 }
}

void Sort_half(int len,int *arr)
{
 int temp_arr_1[len/2];
 int temp_arr_2[len/2];
 
 for (int i=0; i<len/2; i++)
    temp_arr_1[i] = arr[i];
 for (int i=0; i<len/2; i++) 
    temp_arr_2[i] = arr[len/2+i];
 Sort(len/2,temp_arr_1);
 Sort_dec(len/2,temp_arr_2);
 for (int i=0; i<len/2; i++)
    arr[i]=temp_arr_1[i];
 for (int i=0; i<len/2; i++) 
    arr[len/2+i]=temp_arr_2[i];  
}

