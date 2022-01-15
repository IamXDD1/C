#include <stdio.h>
#include <stdlib.h>

long long int fibonacci(int n);

int main()
{
    int n = 0;
    scanf("%d", &n);
    printf("%lld", fibonacci(n));
    return 0;
}

long long int fibonacci(int n){
    long long int num1 = 0, num2 = 1;
    for(size_t i = 1, temp = 0; i<n; i++)
    {
        temp = num1;
        num1 = num2;
        num2 += temp;
    }
    return num2;
}