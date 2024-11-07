/* HW4
 * task_10.c
 *  
 */


#include <stdio.h> 
int main(void)
{
 int a; 
  scanf("%d", &a);
  if ((a==1)||(a==2)||(a==12))
   {
	printf("winter");  
   } 
  else if ((a>=3)&&(a<=5))
   {
	printf("spring");  
   }
  else if ((a>=6)&&(a<=8))
   {
	printf("summer");  
   }
  else if ((a>=9)&&(a<=11))
   {
	printf("autumn");  
   }
 return 0; 
}


 
	
