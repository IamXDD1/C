#include <stdio.h>
#include <stdlib.h>

int main()
{
    float kg_water = 0;
    float initial_T = 0;
    float final_T = 0;
    float energy = 0;

    printf("Enter the amount of water in kilograms¡G");
    scanf("%f", &kg_water);
    printf("Enter the initial temperature¡G");
    scanf("%f", &initial_T);
    printf("Enter the final temperature¡G");
    scanf("%f", &final_T);

    energy = kg_water * (final_T - initial_T) * 4184;

    printf("The energy needed is %f", energy);

    return 0;
}
