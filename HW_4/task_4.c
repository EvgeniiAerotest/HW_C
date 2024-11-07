/* HW4
 * task_4.c
 *  
 */


#include <stdio.h> 
int main(void)
{
 int a, b, c, d, e, min, max, sum; 
  scanf("%d%d%d%d%d", &a, &b, &c, &d, &e); 
  max =  a > b ?  a : b;
  max = max> c ? max: c;
  max = max> d ? max: d;
  max = max> e ? max: e;
  
  min =  a < b ?  a : b;
  min = min< c ? min: c;
  min = min< d ? min: d;
  min = min< e ? min: e;
  
  sum = min+max;
  printf("%d\n", sum);
 return 0; 
}


 
	
