#include <stdio.h>

int FibConsecutive(int a, int b){
    int x=1, y=1, temp;

    while (y < b)
    {
        temp = x+y;
        x=y;
        y = temp;

        if ((x==a && y==b) || (x==a && y==a))
        {
            return 1;
        }
    }
    return 0; 
}

int main() {
    int n1, n2;

    scanf("%d%d", &n1, &n2);

   if (FibConsecutive(n1,n2))
   {
    printf("yes\n");
   } else{
    printf("no\n");
    
   }
   


    return 0;
}