#ifndef TEMP_API_H
#define TEMP_API_H

#include <stdint.h>

#define SIZE 600000

struct sensor {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;    
    int8_t t;
};

// Прототипы функций
void SortByT(struct sensor* info, int n);
void SortByDate(struct sensor* info, int n);
int AddInfo(struct sensor* info);
void print(struct sensor* info, int number);
float TempAvrM(struct sensor* info, int n, uint16_t year, uint8_t month);
int TempMinM(struct sensor *info, int n, uint16_t year, uint8_t month);
int TempMaxM(struct sensor *info, int n, uint16_t year, uint8_t month);
int TempMinY(struct sensor *info, int n);
int TempMaxY(struct sensor *info, int n);
float TempAvrY(struct sensor *info, int n);
void print_month(struct sensor *info, int data_count, int month_int);
void print_all_monthes(struct sensor *info, int data_count);
void print_one_month(struct sensor *info, int data_count, int month_int);
void print_year(struct sensor *info, int data_count);
int Data_Month_Count(struct sensor *info, int n, uint16_t year, uint8_t month);
int load_data_file(char* filename,struct sensor *info);

#endif