#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    for(int i=1; i<=500; i++)
    {
        for(int side1 = 1; side1<i; side1++)
        {
            for(int side2 = 1; side2 < side1; side2++)
            {
                if(pow(i, 2) == pow(side1, 2) +pow(side2, 2)) printf("%d %d %d\n", side2, side1, i);
            }
        }
    }
    return 0;
}