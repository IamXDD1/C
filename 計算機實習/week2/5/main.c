#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x0 = 0, y0 = 0;
    float x1 = 0, y1 = 0;
    float x2 = 0, y2 = 0;

    scanf("%f %f", &x0, &y0);
    scanf("%f %f", &x1, &y1);
    scanf("%f %f", &x2, &y2);

    float n = (x1-x0)*(y2-y0) - (x2-x0)*(y1-y0);

    if(n > 0) printf("left");
    else if(n < 0) printf("right");
    else if(n == 0) printf("on");
    return 0;
}
