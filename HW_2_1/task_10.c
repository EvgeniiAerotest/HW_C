/* HW2_1
 * task_10.c
 *
 *
 */

#include <stdio.h>
#include <stdint.h>

int extractExp(float f)
{
    union
    {
        float f;
        struct
        {
            uint32_t mantissa : 23;
            uint32_t exp : 8;
            uint32_t s : 1;
        } field;
    } fl;
    fl.f = f;
    return fl.field.exp;
}

int main(void)
{
    float f = 0;
    scanf("%f", &f);
    printf("%d\n", extractExp(f));
    return 0;
}
