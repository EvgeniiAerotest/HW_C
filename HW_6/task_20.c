/* HW6
 * task_20.c
 *
 */
 
#include <stdio.h>
int main(void)
{   
 char c;
 int count=0;
 int open_flag=0;
 
 while( (c=getchar())!='.')
 {
    if(c=='(')
    { 
       open_flag=1;
       count++;
    }
    if(c==')' && open_flag==1)
	   count--;
 }
 if (count==0 && open_flag==1)
	printf("YES");
 else
    printf("NO");
 return 0;  
}




