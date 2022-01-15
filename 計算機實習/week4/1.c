#include <stdio.h>
#include <stdlib.h>

int main()
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<=i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");

    for(int i=0; i<10; i++)
    {
        for(int j=i; j<10; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");

    for(int i=0; i<10; i++)
    {
        for(int j=1; j<=i; j++)
        {
            printf(" ");
        }

        for(int j=i; j<10; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");

    for(int i=0; i<10; i++)
    {
        for(int j=i+1; j<10; j++)
        {
            printf(" ");
        }

        for(int j=0; j<=i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}