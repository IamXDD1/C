#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    for(int input=2; input<=1000; input++)
    {
        int check = 1;
        for(int j=2; j<=sqrt(input); j++)
        {
            if(input%j == 0)
            {
                check = 0;
                break;
            }
        }
        if(check) printf("%d\n", input);
    }
    return 0;
}