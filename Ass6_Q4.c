#include <stdio.h>
int removedupl_k(int a[], int len, int k) {
int w = 0; //w-->write
int r = 0; //r-->read

while(r < len) {
        int curr = a[r];
        int count = 1;
        while(r+1 < len && a[r] == a[r+1]) {
                count++;
                r++;
        }
if(count >= k) {
a[w++] = curr;
}
else {
for(int i = 0; i < count; i++) {
a[w++] = curr;
}
}
r++;
}
return w;
}
