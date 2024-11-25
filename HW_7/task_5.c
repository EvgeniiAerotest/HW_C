/* HW7
 * task_5.c
 *
 */

#include <stdio.h>
 
int СonvtoBinRec(int num, int pos);

int main(void)
{
 int n;
 scanf("%d", &n);   
 printf("%d\n",СonvtoBinRec(n,1));   
}

int СonvtoBinRec(int num, int pos)
{
 if (num > 0)
    return (num % 2)*pos + СonvtoBinRec(num / 2, pos*10);
 return (num);
}
