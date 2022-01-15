#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    for(int i=10000; i<=100000; i+=10000)
    {
        double pi = 0;
        for(int j=1; j<=i; j++)
        {
            pi += (pow(-1, j+1)/(j*2 -1))*4;
        }
        printf("%lf\n", pi);
    }

    return 0;
}