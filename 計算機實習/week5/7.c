#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    for(int i=5, check_prime = 1, prime1 = 3, prime2 = 3; i <= 1200; i++, check_prime = 1)
    {
        for(int j=2; j<=sqrt(i); j++)
        {
            if(i % j == 0)
            {
                check_prime = 0;
                break;
            }
        }

        if(check_prime)
        {
            prime1 = prime2;
            prime2 = i;

            if(prime2 - prime1 == 2) printf("%d %d\n", prime1, prime2);
        }
    }
    return 0;
}