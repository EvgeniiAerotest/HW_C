/* HW3
 * task_2.c
 *  
 */


#include <stdio.h> //Объявить библиотеки ввода-вывода
int main(void)
{
  int a, b, c, sum, mult ; //Объявить переменные
  printf("Input numbers:\n"); //Вывести на экран подсказку
  scanf ("%d%d%d", &a, &b, &c); //Считать три целых числа и записать их по адресу a,b,c
  sum = a + b + c; //Сложить три числа и поместить сумму в sum
  mult = a * b * c; //Перемножить три числа и поместить произведение в mult
  printf("%d+%d+%d=%d\n", a, b, c, sum); //Вывести на экран строку вида %d+%d+%d=%d
  printf("%d*%d*%d=%d\n", a, b, c, mult);//Вывести на экран строку вида %d*%d*%d=%d
  return 0; //Завершить программу 
}




