#include <stdio.h>
#include <limits.h>
int main()
{
    int num, count = 0, max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    while ((num = getchar()) != EOF)
    {
        if (num == 'n')
            continue;

        ungetc(num, stdin);
        scanf("%d", &num);
        if (num > max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = num;
        }
        else if (num > max2 && num != max1)
        {

            max3 = max2;
            max2 = num;
        }
        else if (num > max3 && num != max1 && num != max2)
        {
            max3 = num;
        }
        count++;
    }
    if (count < 3)
        printf("not found\n");
    else
        printf("\n%d\n", max3);

    return 0;
}