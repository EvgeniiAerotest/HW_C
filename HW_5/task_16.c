/* HW5
 * task_16.c
 */
#include <stdio.h>
int a;
int b;
int main(void)
{
 scanf("%d%d", &a, &b);
 while(a != b)
 {
    if (a>b)
	    a -= b;
	else 
	    b -= a;    
 } 
printf("%d\n",a);
return 0;
}

