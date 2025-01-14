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
  int minus_flag = 0; //
  int data_count = 0;
  int rez = 0;
  int month_int = 0;
  int p_flag = 0;
  int m_flag = 0;
  int f_flag = 0;
  char print_mode[2];
  char name[] = "temperature_small.csv";

  while ((rez = getopt(argc, argv, "hp:f:m:")) != -1)
  {
    switch (rez)
    {
    case 'h':
      print_help();
      break;
    case 'f':
      strcpy(name, optarg);
      f_flag = 1;
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

  if (p_flag == 0 && f_flag == 0 && m_flag == 0) // no arguments
  {
    print_help();
  }
  else
  {
    data_count = load_data_file(name, info);
    if (data_count >= 0)
    {
      if (p_flag == 1) // if print data mode specified
      {
        if (print_mode[0] == 'T')
          SortByT(info, data_count);
        else if (print_mode[0] == 'D')
          SortByDate(info, data_count);
        print(info, data_count);
      }
      if (m_flag == 1) // month specified
      {
        print_one_month(info, data_count, month_int);
      }
      else // month not specified
      {
        print_all_monthes(info, data_count);
        print_year(info, data_count);
      }
    }
  }
  free(info);
  return 0;
}
