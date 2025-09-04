#include <limits.h>
int second_max(int arr[], int len)
{  if(len == 1){
	return INT_MIN;
}
	if(len == 2){
	   return arr[1]>arr[0] ? arr[0] : arr[1];
	}
int tmax, smax, max;
    tmax = arr[0];
    smax = arr[1];
    max = arr[2];
    for(int i = 3; i < len; i++){
        if(max < arr[i]) {
            tmax = smax;
            smax = max;
            max = arr[i];
        } else if(max >= arr[i] && smax <=arr[i]){
            tmax = smax;
            smax = arr[i];
        } else if(max >= arr[i] && tmax <= arr[i]){
            tmax = arr[i];
        }
        
    }
    return smax;
}