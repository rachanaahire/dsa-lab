#include <stdio.h>
#include <math.h>
int main(){
    double x, value;
    printf("enter value of x:");
    scanf("%lf",&x);
    value = exp(x);
    printf("exponential of %0.2lf = %0.4lf",x,value);
    return 0;
}


