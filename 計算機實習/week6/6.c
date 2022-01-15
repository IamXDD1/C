#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x=0;
    scanf("%d", &x);
    double old_y = 1;
    double x_divide_y = (double)x/old_y;
    double average = (old_y + x_divide_y)/2;

    for(double new_y = average; fabs(old_y - new_y) > 0.00001 ;)
    {
        old_y = average;
        x_divide_y = (double)x / old_y;
        average = (old_y + x_divide_y)/2;

        old_y = new_y;
        new_y = average;
    }
    printf("%.5lf", old_y);
    return 0;
}