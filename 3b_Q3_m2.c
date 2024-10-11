#include <stdio.h>

int main()
{
    int a, b, c, d;

    // Read four integers
    printf("Enter four integers: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    // Print integers in increasing order using if-else statements
    if (a <= b && a <= c && a <= d)
    {
        printf("%d ", a);
        if (b <= c && b <= d)
        {
            printf("%d ", b);
            if (c <= d)
            {
                printf("%d %d\n", c, d);
            }
            else
            {
                printf("%d %d\n", d, c);
            }
        }
        else if (c <= b && c <= d)
        {
            printf("%d ", c);
            if (b <= d)
            {
                printf("%d %d\n", b, d);
            }
            else
            {
                printf("%d %d\n", d, b);
            }
        }
        else
        {
            printf("%d ", d);
            printf("%d %d\n", b, c);
        }
    }
    else if (b <= a && b <= c && b <= d)
    {
        printf("%d ", b);
        if (a <= c && a <= d)
        {
            printf("%d ", a);
            if (c <= d)
            {
                printf("%d %d\n", c, d);
            }
            else
            {
                printf("%d %d\n", d, c);
            }
        }
        else if (c <= a && c <= d)
        {
            printf("%d ", c);
            if (a <= d)
            {
                printf("%d %d\n", a, d);
            }
            else
            {
                printf("%d %d\n", d, a);
            }
        }
        else
        {
            printf("%d ", d);
            printf("%d %d\n", a, c);
        }
    }
    else if (c <= a && c <= b && c <= d)
    {
        printf("%d ", c);
        if (a <= b && a <= d)
        {
            printf("%d ", a);
            if (b <= d)
            {
                printf("%d %d\n", b, d);
            }
            else
            {
                printf("%d %d\n", d, b);
            }
        }
        else if (b <= a && b <= d)
        {
            printf("%d ", b);
            if (a <= d)
            {
                printf("%d %d\n", a, d);
            }
            else
            {
                printf("%d %d\n", d, a);
            }
        }
        else
        {
            printf("%d ", d);
            printf("%d %d\n", a, b);
        }
    }
    else
    {
        printf("%d ", d);
        if (a <= b && a <= c)
        {
            printf("%d ", a);
            if (b <= c)
            {
                printf("%d %d\n", b, c);
            }
            else
            {
                printf("%d %d\n", c, b);
            }
        }
        else if (b <= a && b <= c)
        {
            printf("%d ", b);
            if (a <= c)
            {
                printf("%d %d\n", a, c);
            }
            else
            {
                printf("%d %d\n", c, a);
            }
        }
        else
        {
            printf("%d ", c);
            printf("%d %d\n", a, b);
        }
    }

    return 0;
}
