#include<stdio.h>
# define SIZE 32 

int maxdif(int arr[] , int l){
int max , i=0 , a=1;

while(i < l) {

while(a < l){
	int max1,max2;
	arr[i];
	
	arr[a];
	max1 = arr[i] - arr[a];
	max2 = arr[a] - arr[i];
	if(max1<max2){
	max = max2;
	}else{
	max = max1;}
	
a++;
}
i++;
}
return max;
}

int main() {
int a[SIZE], lena = 0, max;

while(SIZE > lena && scanf("%d", &a[lena])) {
	lena++;	
}
max = maxdif(a, lena);
printf("%d", max);

return 0;
}
