/* HW7
 * task_9.c
 *
 */

#include <stdio.h>
  
int is_prime(int n);

int main(void)
{
 int n;
 scanf("%d",&n);    
 is_prime(n) ? printf("YES") : printf("NO"); 
}

int is_prime(int n)
{   
 static int prime_flag=1;
 static int i = 2;
    	
 if(n==1)
   return 0;
 else if(i < n)
 {
  if (n%i == 0)
    prime_flag=0;
  else
  {
   i++;
   is_prime(n);
  }      
 }
 if(prime_flag==0)
   return 0;
 else 
   return 1;    
} 
 

