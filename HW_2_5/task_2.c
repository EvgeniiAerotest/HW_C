#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

#define SIZE 1000

void zFunction(char *s, int z[])
{
    int n = strlen(s);
    for (int i = 1; i < n; i++)
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        {
            z[i]++;
        }
}

int min(int a, int b)
{
    return a < b ? a : b;
}

void zFunction2(char *s, int z[])
{
    int n = strlen(s);
    for (int i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
}

void PrintZ(char *s, int z[])
{
    int n = strlen(s);
    for (int i = 0; i < n; ++i)
        printf("  %c,", s[i]);
    printf("\n");
    for (int i = 0; i < n; ++i)
        printf("%3d,", z[i]);
    printf("\n");
}

int max_suff(char *t, char *p)
{
    char s[SIZE + SIZE] = {0};
    int z[SIZE + SIZE] = {0};
    size_t tlen = strlen(t);
    size_t plen = strlen(p);
    int max_suff = 0;
    sprintf(s, "%s#%s", t, p);
    zFunction(s, z);
    for (size_t i = 0; i < plen; i++)
    {
        if (z[i + tlen + 1] == plen - i)
        {
            max_suff = z[i + tlen + 1];
            return max_suff;
        }
    }
    return max_suff;
}

int main(void)
{
    char t[SIZE] = {0};
    char p[SIZE] = {0};

    scanf("%s", t);
    scanf("%s", p);
    printf("%d %d\n", max_suff(t, p), max_suff(p, t));
    return 0;
}
