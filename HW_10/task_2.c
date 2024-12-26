/* HW10
 * task_2.c
 *
 */

#include <stdio.h>
#include <string.h>

int load_f(char *filename);
void save_f(char *filename, char *str);
void let_dig(int n, char *s);

int main(void)
{
    char s[100] = {0};

    int n = load_f("input.txt");
    let_dig(n, s);
    save_f("output.txt", s);

    return 0;
}

int load_f(char *filename)
{
    int n = 0;
    FILE *f;
    f = fopen(filename, "r");
    fscanf(f, "%d", &n);
    fclose(f);
    return n;
}

void save_f(char *filename, char *str)
{
    FILE *f;
    f = fopen(filename, "w");
    fprintf(f, "%s", str);
    fclose(f);
}

void let_dig(int n, char *s)
{
    int l_count = 0;
    int d_count = 1;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 != 0)
        {
            s[i] = '1' + d_count;
            d_count += 2;
            if (d_count >= 9)
                d_count = 1;
        }
        else
        {
            s[i] = 'A' + (l_count);
            l_count++;
        }
    }
}
