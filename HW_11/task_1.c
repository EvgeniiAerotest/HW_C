/* HW10
 * task_1.c
 *
 */

#include <stdio.h>
#include <string.h>

int load_f(char *filename, char *str);
void save_f(char *filename, char *str, int len);

int main(void)
{
    char s[100];

    int len = load_f("input.txt", s);
    save_f("output.txt", s, len);
    return 0;
}

int load_f(char *filename, char *str)
{
    FILE *f;
    f = fopen(filename, "r");
    fscanf(f, "%[^\n]", str);
    fclose(f);
    return strlen(str);
}

void save_f(char *filename, char *str, int len)
{
    FILE *f;
    f = fopen(filename, "w");
    fprintf(f, "%s, %s, %s %d", str, str, str, len);
    fclose(f);
}
