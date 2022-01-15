#include <stdio.h>
#include <stdlib.h>
#include <math.h>

_Bool isPrime(int num, int factor, int bound);

int main()
{
    int num;
    scanf("%d", &num);
    isPrime(num, 2, sqrt(num)) ? printf("True") : printf("False");

    return 0;
}
_Bool isPrime(int num, int factor, int bound){
    if(bound >= factor)
    {
        if(num%factor == 0) return 0;
        return isPrime(num, factor+1, bound);
    }
    else return 1;
}