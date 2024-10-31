#include <stdio.h>
int main(){
    double x,val,num,Cos,fact,denominator;
    num = 0.9999;
    Cos = 1;
    val = 1;
    fact = 0;
    denominator = 1;
    scanf("%lf",&x);
    while(val>0.000001 || val< -0.000001){
        num = (-1)*num*x*x;
        denominator = (denominator)*(fact+1)*(fact+2);
        val = num/denominator;
        Cos = Cos + val;
        fact = fact + 2;
    }
    printf("%.4f",Cos);
    return 0;
}