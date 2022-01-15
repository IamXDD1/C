#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 0;
    scanf("%d", &num);

    for(int i=0, num2 = num; i<num2; i++, num--)
    {
        for(int j=num; j>0; j--)
            printf("%d ", j);

        for(int j=2; j<=num; j++)
            printf("%d ", j);

        printf("\n");
    }
    return 0;
}