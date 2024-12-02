/*
 *  HW8
 * task_16.c
 *
 */

#include <stdio.h>

#define SIZE 10
 
int Input(int len, int* arr);
void Print(int len, int *arr);
void SwapArr(int i,int j,int *arr);
void Sort(int len,int *arr);
void M_often_Number(int len,int *arr);

int main(void)
{
 int arr[SIZE]={0};
 Input(SIZE, arr);
 Sort(SIZE,arr);
 M_often_Number(SIZE,arr);	
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

void M_often_Number(int len,int *arr)
{
	int count = 1;
	int m_count=0;
	int m_often_num=0;
    for (int i = 1; i < len; i++) 
    {
     if (arr[i] == arr[i - 1])
     {
       count++;
     }
     else
     {
      if (count > m_count)
      {
        m_count = count;
        m_often_num = arr[i - 1];
      }
      count = 1;
     }
    }
    if (count > m_count)
    {
      m_count = count;
      m_often_num = arr[9];
    }
    printf("%d\n", m_often_num);
}

