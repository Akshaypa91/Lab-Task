#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int nums[4], sorted[4], i, mid1, mid2;

    for (i = 0; i < 4; i++) {
        scanf("%d", &nums[i]);
        sorted[i] = nums[i]; 
    }

    qsort(sorted, 4, sizeof(int), compare);

    mid1 = sorted[1];
    mid2 = sorted[2];

    for (i = 0; i < 4; i++) {
        if (nums[i] == mid1 || nums[i] == mid2) {
            printf("%d ", nums[i]);
        }
    }
    
    printf("\n");
    return 0;
}
