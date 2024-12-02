/*
 *  HW8
 * task_3.c
 *
 */

#include <stdio.h>

#define SIZE 10
 
int Input(int len, int* arr);
void Print(int len, int *arr);
float Avg(int len, int* arr);
int Min(int len,int *arr);
int PosMin(int len, int *arr);
int Max(int len,int *arr);
int PosMax(int len,int *arr);

int main(void)
{
 int arr[SIZE]={0};
 Input(SIZE, arr);
 printf("%d %d %d %d",PosMax(SIZE,arr),Max(SIZE,arr),PosMin(SIZE,arr),Min(SIZE, arr)); 	
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

float Avg(int len, int* arr) 
{
 int i,sum=0;
 for(i=0;i<len;i++)
    sum+=arr[i];
 return sum/5.;
}

int Min(int len,int *arr)
{
 int min=arr[0],i;
 for (i = 1; i < len; i++)
    if (min > arr[i]) 
        min = arr[i];
 return min; 
}

int PosMin(int len, int *arr)
{
 int min=arr[0],i,pos=1;

 for (i = 1; i < len; i++)
 {
   if(min > arr[i]) 
   {
      min = arr[i];
      pos = i+1;
   }
 } 
 return pos; 
}

int Max(int len,int *arr)
{
 int max=arr[0],i;
 for (i = 1; i < len; i++)
    if (max < arr[i]) 
        max = arr[i];
 return max;
} 
 
int PosMax(int len,int *arr)
{
 int max=arr[0],i,pos=1;
 for (i = 1; i < len; i++)
 {
    if (max < arr[i])
    { 
      max = arr[i];
      pos = i+1;
    }
 }
 return pos;
}





