#include <stdio.h>
#include <stdlib.h>

int main()
{

    for(int i=0, input=0; i<5; i++)
    {
        scanf("%d", &input);

        for(int j=0; j<input; j++)
        {
            printf("*");
        }

        printf("\n");
    }
    return 0;
}