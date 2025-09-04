#include <stdio.h>

struct pnt {
    int x, y, z;
};

void pArr(struct pnt arr[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d%d%d\n", arr[i].x, arr[i].y, arr[i].z);
    }
}

int main(void)
{
    int n, index;
    scanf("%d", &n);

    struct pnt arr[n];
    for (int i = 0; i < n; i++) {
       scanf("%d %d %d", &arr[i].x, &arr[i].y, &arr[i].z);
    }
    printf("----array----\n");
    pArr(arr, n);
    struct pnt new_pnt;
    scanf("%d", &index);
    scanf("%d %d %d", &new_pnt.x, &new_pnt.y, &new_pnt.z);
    for (int i = n; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = new_pnt;
    printf("----array----");
    pArr(arr, n + 1);
    return 0;
}