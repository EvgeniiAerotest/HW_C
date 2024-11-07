/* HW4
 * task_5.c
 *  
 */


#include <stdio.h> 
int main(void)
{
 int x1, x2, y1, y2; 
 float k,b;
 scanf("%d%d%d%d", &x1, &y1, &x2, &y2);  
 k=(float)(y2-y1)/(x2-x1);
 b=y1-k*x1;  
 printf("%.2f %.2f", k, b);    
 return 0; 
}


 
	
