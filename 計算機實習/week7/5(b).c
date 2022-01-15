#include <stdio.h>
#include <stdlib.h>

unsigned long long int fibonacci();

int main()
{
    printf("%llu", fibonacci());
    return 0;
}

unsigned long long int fibonacci(){
    unsigned long long int num1 = 0, num2 = 1;
    for(unsigned long long int temp = 0;;)
    {
        temp = num1;
        num1 = num2;
        if(num2 + temp < temp) break;
        else num2 += temp;
    }
    return num2;
}