#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    scanf("%s", str);

    int len = strlen(str);
    int count = 0;
    int number[1000] = {0};

    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            for (int k = j + 1; k < len; k++)
            {
                if (str[i] != '0')
                {
                    int num = (str[i] - '0') * 100 + (str[j] - '0') * 10 + (str[k] - '0');
                    if (number[num] == 0)
                    {
                        number[num] = 1;
                        count++;
                    }
                }
            }
        }
    }

    printf("%d\n", count);

    return 0;
}
