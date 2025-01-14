#include "temp_api.h"
#include <stdio.h>
#include <stdint.h>

void cgangeIJ(struct sensor *info, int i, int j)
{
    struct sensor temp;
    temp = info[i];
    info[i] = info[j];
    info[j] = temp;
}

void SortByT(struct sensor *info, int n)
{
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
            if (info[i].t >= info[j].t)
                cgangeIJ(info, i, j);
}

uint64_t DateToInt(struct sensor *info)
{
    return (uint64_t)(info->year) << 32 | info->month << 24 | info->day << 16 | info->hour << 8 | info->minute;
}

void SortByDate(struct sensor *info, int n)
{
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
            if (DateToInt(info + i) >= DateToInt(info + j))
                cgangeIJ(info, i, j);
}

void AddRecord(struct sensor *info, int number, uint16_t year,
               uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, int8_t t)
{
    info[number].year = year;
    info[number].month = month;
    info[number].day = day;
    info[number].hour = hour;
    info[number].minute = minute;
    info[number].t = t;
}

int AddInfo(struct sensor *info)
{
    int counter = 0;
    AddRecord(info, counter++, 2021, 8, 16, 12, 23, 9);
    AddRecord(info, counter++, 2021, 9, 16, 17, 2, -9);
    AddRecord(info, counter++, 2021, 9, 16, 23, 10, 8);
    AddRecord(info, counter++, 2021, 9, 16, 10, 17, 17);
    return counter;
}

void print(struct sensor *info, int number)
{
    printf("===================================\n");
    for (int i = 0; i < number; i++)
        printf("%04d-%02d-%02d-%02d.%02d t=%3d\n",
               info[i].year,
               info[i].month,
               info[i].day,
               info[i].hour,
               info[i].minute,
               info[i].t);
}

void print_month(struct sensor *info, int data_count, int month_int)
{
    if (Data_Month_Count(info, data_count, 2021, month_int))
        printf("2021  %2d  %5d  %7.2f  %6d  %6d\n",
               month_int,
               Data_Month_Count(info, data_count, 2021, month_int),
               TempAvrM(info, data_count, 2021, month_int),
               TempMinM(info, data_count, 2021, month_int),
               TempMaxM(info, data_count, 2021, month_int));
    else
        printf("2021  %2d  %5d  %s \n",
               month_int,
               Data_Month_Count(info, data_count, 2021, month_int),
               "  no data in this month");
}

void print_one_month(struct sensor *info, int data_count, int month_int)
{
    printf("Year Month NuVal MonthAvr MonthMin MonthMax\n");
    print_month(info, data_count, month_int);
}

void print_all_monthes(struct sensor *info, int data_count)
{
    printf("Year Month NuVal MonthAvr MonthMin MonthMax\n");
    for (int i = 1; i <= 12; i++)
    {
        print_month(info, data_count, i);
    }
}

void print_year(struct sensor *info, int data_count)
{
    printf("Year statistics: average is %.2f, min is %d, max is %d\n",
           TempAvrY(info, data_count), TempMinY(info, data_count), TempMaxY(info, data_count));
}

float TempAvrM(struct sensor *info, int n, uint16_t year, uint8_t month)
{
    int temp_var = 0, count = 0;
    float res = 0;
    for (int i = 0; i < n; ++i)
    {
        if (info[i].year == year && info[i].month == month)
        {
            temp_var += info[i].t;
            count++;
        }
    }
    res = (float)temp_var / (float)count;
    return res;
}

int TempMinM(struct sensor *info, int n, uint16_t year, uint8_t month)
{
    int min_temp = -99;
    int f_rec_flag = 0;

    for (int i = 0; i < n; i++)
    {
        if (info[i].year == year && info[i].month == month)
        {
            if (f_rec_flag == 0)
            {
                f_rec_flag = 1;
                min_temp = info[i].t;
            }
            if (info[i].t < min_temp)
                min_temp = info[i].t;
        }
    }
    return min_temp;
}

int TempMaxM(struct sensor *info, int n, uint16_t year, uint8_t month)
{
    int max_temp = 99;
    int f_rec_flag = 0;

    for (int i = 0; i < n; i++)
    {
        if (info[i].year == year && info[i].month == month)
        {
            if (f_rec_flag == 0)
            {
                f_rec_flag = 1;
                max_temp = info[i].t;
            }
            if (info[i].t > max_temp)
                max_temp = info[i].t;
        }
    }
    return max_temp;
}

int TempMinY(struct sensor *info, int n)
{
    int min_temp = info[0].t;

    for (int i = 0; i < n; i++)
    {
        if (info[i].t < min_temp)
            min_temp = info[i].t;
    }
    return min_temp;
}

int TempMaxY(struct sensor *info, int n)
{
    int max_temp = info[0].t;

    for (int i = 0; i < n; i++)
    {
        if (info[i].t > max_temp)
            max_temp = info[i].t;
    }
    return max_temp;
}

float TempAvrY(struct sensor *info, int n)
{
    int temp_var = 0, count = 0;
    float res = 0;
    for (int i = 0; i < n; ++i)
        temp_var += info[i].t;
    res = (float)temp_var / (float)n;
    return res;
}

int Data_Month_Count(struct sensor *info, int n, uint16_t year, uint8_t month)
{
    int data_month_count = 0;
    int f_rec_flag = 0;

    for (int i = 0; i < n; i++)
    {
        if (info[i].year == year && info[i].month == month)
        {
            if (f_rec_flag == 0)
            {
                f_rec_flag = 1;
            }
            data_month_count++;
        }
    }
    return data_month_count;
}

int load_data_file(char *filename, struct sensor *info)
{
    int data_count = 0;
    int minus_flag = 0;

    FILE *open;
    open = fopen(filename, "r");
    if (open == NULL)
    {   
        printf("file open error");
        return -1;
    }
    int counter = 0;
    int arr[6] = {0};
    char ch;
    while ((ch = fgetc(open)) != EOF)
    {
        if (ch == ';')
        {
            counter++;
            if (counter > 6)
                counter = 0;
        }
        else if (ch == '\n')
        {
            if (counter == 5)
            {
                if (minus_flag == 1)
                {
                    minus_flag = 0;
                    arr[5] = arr[5] * -1;
                }

                info[data_count].year = arr[0];
                info[data_count].month = arr[1];
                info[data_count].day = arr[2];
                info[data_count].hour = arr[3];
                info[data_count].minute = arr[4];
                info[data_count].t = arr[5];

                data_count++;
            }
            else
                printf("ERROR %d = %d;%d;%d,%d;%d;%d\n", counter, arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);
            counter = 0;
            arr[0] = arr[1] = arr[2] = arr[3] = arr[4] = arr[5] = 0;
        }
        else if (ch == '-')
            minus_flag = 1;
        else if (ch >= '0' && ch <= '9')
            arr[counter] = arr[counter] * 10 + ch - '0';
        else if (ch != 0xD && ch != 0x20)
            counter = 0;
    }

    return data_count;
}