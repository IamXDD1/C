#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double sum = 0;
    for(int i=1; i<1000; i++)
    {
        sum += sqrt(i+1);
        sum -= sqrt(i);
    }
    printf("%.4lf", sum);
    return 0;
}