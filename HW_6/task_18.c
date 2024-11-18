/* HW6
 * task_18.c
 *
 */
 
#include <stdio.h> 
 
int is_digit(char c);

int main(void)
{   
 char c;
 int counter=0;
 
 while( (c=getchar())!='.')
 {
  counter=is_digit(c);
 }
 printf("%d", counter);
 return 0;  
}




int is_digit(char c)
{
  static int count=0;
  	
  if(c>='0' && c<='9') 
     count++;
  return count;	
}
