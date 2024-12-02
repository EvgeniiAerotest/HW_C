/*
 *  HW8
 * task_7.c
 *
 */

#include <stdio.h>

#define SIZE 10
 
int Input(int len, int* arr);
void Print(int len, int *arr);
void Inverse(int len,int *arr);
void H_Inverse(int len,int *arr);

int main(void)
{
 int arr[SIZE]={0};
 Input(SIZE, arr);
 H_Inverse(SIZE,arr);
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

void Inverse(int len,int *arr)
{ 	
  for (int i = 0; i < len/2; i++)
  {
    int temp_var = arr[i];
    arr[i] = arr[len-1-i];
    arr[len-1-i] = temp_var;  
  } 	
}

void H_Inverse(int len,int *arr)
{ 	
  for (int i = 0; i < 2; i++)
  {
    int temp_var = arr[i];
    arr[i] = arr[4-i];
    arr[4-i] = temp_var;  
  }  
  for (int i = 0; i < 2; i++)
  {
    int temp_var = arr[i+5];
    arr[i+5] = arr[len-1-i];
    arr[len-1-i] = temp_var;  
  }    	
}





