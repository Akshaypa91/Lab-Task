#include <stdio.h>

int max_repeated(int *arr, int len) {
    int max_count = 0; 
    int result = arr[0]; 

    for (int i = 0; i < len; i++) {
        int count = 0;

        for (int j = 0; j < len; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        if (count > max_count || (count == max_count && i > result)) {
            max_count = count;
            result = arr[i];
        }
    }

    return result;
}
