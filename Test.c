#include <stdio.h>

int main(void)
{
int n, sum = 0, ct = 1;

scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) {
		       printf("-%d", ct);
       			sum -= ct;
    			} else {
        		if (i == 1) {
				printf("%d", ct);
        			} else {
					printf("+%d", ct);
        				}
					sum += ct; 
    						}
					ct += 2;
		}
			printf("%d\n", sum);
		return 0;
}
