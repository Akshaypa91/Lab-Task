#include <stdio.h>

int main() {
    
    int n, sum=0, ct=1;
//ct is current_term

scanf("%d", &n);

for (int i = 1; i <= n; i++)
{
    if (i % 2 == 0)
    {
       printf("-%d", ct);
       sum -= ct;
    } else{
        if (i == 1)
        {
            printf("%d", ct);
        } else{
                        printf("+%d", ct);
        }
        sum += ct; 
    }
    ct += 2; 
}
   printf("\n%d\n", sum);
   
    return 0;
}