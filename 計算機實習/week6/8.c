#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int num);

int main()
{
    for(int i=2; i<=31; i++)
    {
        if(isPrime(i))
        {
            int num = pow(2, i)-1;

            if(isPrime(num)) printf("%d %d\n", i, num);
        }
    }
    return 0;
}

int isPrime(int num){

    int n = sqrt(num);
    int prime_check = 1;
    for(int i=2; i<=n; i++)
    {
        if(num % i == 0) prime_check = 0;
    }

    if(prime_check) return 1;
    else return 0;
}