/*
 *  HW8
 * task_10.c
 *
 */

#include <stdio.h>

#define SIZE 12
 
int Input(int len, int* arr);
void Print(int len, int *arr);
void R_Shift(int len,int *arr);
void R_Shift_4(int len,int *arr);

int main(void)
{
 int arr[SIZE]={0};
 Input(SIZE, arr);
 R_Shift_4(SIZE,arr);
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

void R_Shift_4(int len,int *arr)
{ 	
  for (int i = 0; i < 4; i++)
  {
    R_Shift(len,arr);  
  }  
}

