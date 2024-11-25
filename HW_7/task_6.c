/* HW7
 * task_6.c
 *
 */
#include <stdio.h>
 
void print_rev (void);

int main(void)
{
 print_rev();
 return 0;
}

void print_rev (void)
{
 char ch;
 scanf ("%c", &ch); 
 if (ch != '.')
 {
   print_rev (); 
   printf ("%c", ch); 
 }
} 


