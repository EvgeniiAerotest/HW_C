/*
 *  HW8
 * task_15.c
 *
 */

#include <stdio.h>

#define SIZE 10
 
int Input(int len, int* arr);
void Print(int len, int *arr);
void Sort_pos_neg(int len,int *arr);

int main(void)
{
 int arr[SIZE]={0};
 Input(SIZE, arr);
 Sort_pos_neg(SIZE,arr);	
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
}

void Sort_pos_neg(int len,int *arr)
{
  int pos_arr[len];
  int neg_arr[len];
  int neg_count=0;
  int pos_count=0;
  
  for (int i=0; i<len; i++)
  {
    if (arr[i]<0) 
    {
     neg_count++;
     neg_arr[neg_count-1] = arr[i];
    }
  }
  for (int i=0; i<len; i++)
  {
    if (arr[i]>0)
    {
     pos_count++;
     pos_arr[pos_count-1] = arr[i];
    }
  }
  Print(pos_count, pos_arr);
  Print(neg_count, neg_arr);  
}

