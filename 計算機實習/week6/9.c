#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int num);
int reverse(int number);

int main()
{
    for(int count=0, i=2; count < 120; i++)
    {

        if(isPrime(i))
        {
            int num = reverse(i);

            if(isPrime(num))
            {
                printf("%d ", i);
                count++;
                if(count % 10 == 0) printf("\n");
            }
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
int reverse(int number){
    int temp = 0;
    for(;number != 0; number/=10)
    {
        temp *= 10;
        temp += number%10;
    }
    return temp;
}