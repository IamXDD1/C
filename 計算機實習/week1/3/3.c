#include <stdio.h>
#include <stdlib.h>

int main()
{
    float acceleration = 0, speed = 0, min_length = 0;
    printf("Enter speed and acceleration¡G");
    scanf("%f %f", &speed, &acceleration);

    min_length = (speed*speed) / (2*acceleration);

    printf("The minimum runway length for this airplane is %f meters.", min_length);

    return 0;
}
