/*
 *  HW8
 * task_9.c
 *
 */

#include <stdio.h>

#define SIZE 10
 
int Input(int len, int* arr);
void Print(int len, int *arr);
void R_Shift(int len,int *arr);

int main(void)
{
 int arr[SIZE]={0};
 Input(SIZE, arr);
 R_Shift(SIZE,arr);
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

void R_Shift(int len,int *arr)
{ 
  int temp = arr[len-1];	
  for (int i = len-1; i > 0; i--)
  {
    arr[i] = arr[i-1];  
  }  
  arr[0] = temp;
}



