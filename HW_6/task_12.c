/* HW6
 * task_12.c
 *
 */
 
#include <stdio.h> 
 
float expon (float n, int p);
int factorial(int n);
float sinus(float x);


int main(void)
{
	int x;
	scanf("%d", &x);
    printf("%.3f", sinus(x));
}


float expon(float n, int p)
{
  float mult=1;
  for (int i = 1; i <= p; i++)
  {
	  mult*=n;
  }
  return(mult);
}

int factorial(int n)
{
  int factorial=1;	
  for (int i=1; i<=n; i++)
  {
	  factorial = factorial*i;
  }
  return factorial;
}

float sinus(float x)
{
  float radx=0;
  float sin=0;
  
  radx = (x*3.142)/180;
  sin = radx - (expon(radx, 3)/factorial(3))+(expon(radx, 5)/factorial(5))-(expon(radx, 7)/factorial(7));
  
  return(sin);
   	
}


