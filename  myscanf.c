include<stdio.h>
#include <math.h>
    int myscanf(char *format, void *arg)
{
    switch (format[1])
    {
    case 'd':
        int *p = (int *)arg, i = 0;
        char in[10];
        while (i < 10)
        {
            in[i] = getchar();
            if (in[i] - '0' <= '9' - '0' || in[0] == '-')
            {
                ;
            }
            else
            {
                break;
            }
            i++;
        }
        *p = atoi(in);
    }
}