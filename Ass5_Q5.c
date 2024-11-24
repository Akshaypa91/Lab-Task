#include <stdio.h>

int removedupl_k(int a[], int len, int k) {
    int count[128] = {0};
    int added[128] = {0}; 
    int new_len = 0;

    for (int i = 0; i < len; i++) {
        count[a[i]]++;
    }

    for (int i = 0; i < len; i++) {
        if (count[a[i]] >= k) {
            if (!added[a[i]]) {
                a[new_len++] = a[i];
                added[a[i]] = 1;
            }
        } else {
            a[new_len++] = a[i];
        }
    }

    return new_len;
}
