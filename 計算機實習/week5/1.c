#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i = 1;
    for(;;i++)
    {
        if(pow(i, 3) > 12000) break;
    }
    printf("%d", i);
    return 0;
}