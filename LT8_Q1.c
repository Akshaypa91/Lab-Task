#include <stdio.h>
int main(void)
{
	int arr[16];
	int len = 0, max, count = 1;

	scanf("%d", &arr[0]);
	int iter = 1;
	while ( scanf("%d", &arr[iter]) == 1 &&iter < 16) {
	         iter++;
	         len++;
	}
		max = arr[0];
	for (int j = 1; j <= len; j++) {
	if(max>= arr[j]){
	    if(max == arr[j]){
		count += 1;
	    }
	}else{
	count = 1;
	max = arr[j];
	}
	}
	printf("%d %d", max, count);
		return 0;
}