#include <stdio.h>

int main() {

    int sum =0;
    int a=1;
    int value;
    for(int i=0; i<a; i++){
        scanf("%d", &value);
        
        if(value == -1){
            sum=sum-1;
            break;
        }
        sum = sum+value;
        a++;
    }
    printf("%d", sum);
   

    return 0;
}
