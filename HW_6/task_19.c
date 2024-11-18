/* HW6
 * task_19.c
 *
 */

#include <stdio.h>
 
int digit_to_num(char c);


int main(void)
{   
 char c;
 int temp=0;
 int sum=0;
 
 while( (c=getchar())!='.')
 {
  temp=digit_to_num(c);
  if (temp != 10)
	sum+=temp;
 }
 printf("%d", sum);
 return 0;  
}



int digit_to_num(char c)
{ 	
  if(c>='0' && c<='9')
  { 
     c-=0x30;
     return c;
  }
  else
	 return 10;
}
