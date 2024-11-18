/* HW6
 * task_8.c
 *
 */
#include <stdio.h> 

void СonvtoBigL(void);

int main(void)
{   
 СonvtoBigL();
 return 0;  
}


void СonvtoBigL(void)
{
 char c;
 while( (c=getchar())!='.')
 {
  if(c>='a' && c<='z') 
     putchar('A' + (c-'a'));
  else
     putchar(c);
 }


}

