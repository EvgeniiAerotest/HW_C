/* HW8
 * task_1.c
 *
 */

#include <stdio.h>
 
int Input(int len, int* arr);
void Print(int len, int *arr);
float Avg(int len, int* arr);

int main(void)
{
 int arr[5]={0};
 Input(5, arr);
 printf("%.3f ", Avg(5, arr)); 	
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


