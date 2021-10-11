#include <stdio.h>
#include <stdlib.h>

int main()
{
    float circle1_x = 0, circle1_y = 0, circle1_r = 0;
    float circle2_x = 0, circle2_y = 0, circle2_r = 0;
    float center_distance = 0;

    scanf("%f %f %f", &circle1_x, &circle1_y, &circle1_r);
    scanf("%f %f %f", &circle2_x, &circle2_y, &circle2_r);

    center_distance = (circle1_x-circle2_x)*(circle1_x-circle2_x) + (circle1_y-circle2_y)*(circle1_y-circle2_y);


    if(center_distance <= (circle1_r-circle2_r)*(circle1_r-circle2_r)) printf("Inside");
    else if(center_distance <= (circle1_r+circle2_r)*(circle1_r+circle2_r)) printf("Overlap");
    else printf("Not overlap");

    return 0;
}
