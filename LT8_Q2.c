#include <stdio.h>
int findmax(int *arr, int len)
{       int max;
        max = arr[0];
        for(int i = 1; i < len; i++){
            if(max < arr[i]){
                max = arr[i];
            }
        }
    return max;
}