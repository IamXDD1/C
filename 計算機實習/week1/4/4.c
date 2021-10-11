#include <stdio.h>
#include <stdlib.h>

int main()
{
    float distance = 0;
    float miles_per_gallon = 0;
    float price_per_gallon = 0;
    float cost_of_driving = 0;

    printf("Enter the driving distance¡G");
    scanf("%f", &distance);

    printf("Enter miles per gallon¡G");
    scanf("%f", &miles_per_gallon);

    printf("Enter price per gallon¡G");
    scanf("%f", &price_per_gallon);

    cost_of_driving = distance/miles_per_gallon * price_per_gallon;

    printf("The cost of driving is $%f¡G", cost_of_driving);
    return 0;
}
