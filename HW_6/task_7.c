/* HW6
 * task_7.c
 *
 */

#include <stdio.h>
 
void СonvtoPsyst(int n, int p);

int main(void)
{
 int n,p;
 scanf("%d%d", &n, &p);   
 СonvtoPsyst(n,p);  
}


void СonvtoPsyst(int n, int p)
{
 int result = 0;
 int rem = 0;
 int counter = 0;
 int position = 1;
 while (n != 0)
 {
	 rem = n%p;
	 counter++;
	 for (int i=1; i<counter; i++)
	 {
		 position = position*10;
	 }
	 
	result = result + rem*position;
	position=1;
	n=n/p;
 }
 printf("%d\n",result);
}
