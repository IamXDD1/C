#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int input = 0;
    scanf("%ld", &input);

    for(int i=0; i<10; i++, input/=10)
    {
        printf("%ld\n", input%10);
    }
    return 0;
}