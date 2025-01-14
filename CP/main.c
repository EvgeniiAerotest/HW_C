#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "temp_api.h"

int main(int argc, char **argv)
{
  struct sensor *info = malloc(SIZE * sizeof(struct sensor));
  if (info == NULL)
  {
    printf("memory allocation error\n");
    exit(1);
  }
  int minus_flag = 0;
  int data_count = 0;
  int rez = 0;
  int month_int = 0;
  int p_flag = 0;
  int m_flag = 0;
  char print_mode[2];
  char name[] = "temperature_small1.csv";

  while ((rez = getopt(argc, argv, "hp:f:m:")) != -1)
  {
    switch (rez)
    {
    case 'h':
      printf("This is description of this application usage:\n");
      printf("-h This help text;\n");
      printf("-f Specify data file;\n");
      printf("-m Specify month to print statistics;\n");
      printf("   if clear all monthes and year statistics will be printed\n");                
      printf("-p Specify file print mode: \n");
      printf("   T - sort data file by temperature\n");
      printf("   D - sort data file by date\n");
      printf("   if clear data file will not be printed\n");
      break;
    case 'f':
      strcpy(name, optarg);
      break;
    case 'm':
      month_int = atoi(optarg);
      m_flag = 1;
      break;
    case 'p':
      p_flag = 1;
      strcpy(print_mode, optarg);
      break;
    case '?':
      printf("Error found !\n");
      break;
    };
  };

  data_count = load_data_file(name, info);
  if (p_flag == 1)
  {
    if (print_mode[0] == 'T')
      SortByT(info, data_count);
    else if (print_mode[0] == 'D')
      SortByDate(info, data_count);
    print(info, data_count);
  }
  if (m_flag == 1)
  {
    print_one_month(info, data_count, month_int);
  }
  else
  {
    print_all_monthes(info, data_count);
    print_year(info, data_count);
  }
  free(info);
  return 0;
}