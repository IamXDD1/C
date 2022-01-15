#include <stdio.h>
#include <stdlib.h>

int getPentagonalNumber(int n);

int main()
{
    for(int i=1; i<=100; i++)
    {
        printf("%7d", getPentagonalNumber(i));
        if(i % 10 == 0) printf("\n");
    }

    return 0;
}

int getPentagonalNumber(int n){
    return n*(n*3-1) / 2;
}