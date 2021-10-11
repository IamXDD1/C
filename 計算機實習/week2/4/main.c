#include <stdio.h>
#include <stdlib.h>

int main()
{
    float BMI = 0;
    float weight_kg;
    float height_m;

    scanf("%f %f", &weight_kg, &height_m);

    BMI = weight_kg / height_m / height_m;

    printf("%.2f\n", BMI);
    if(BMI < 18.50) printf("Underweight");
    else if(BMI >= 18.50 && BMI < 25.00) printf("Normal");
    else if(BMI >= 25.00 && BMI < 30.00) printf("Overweight");
    else if(BMI >= 30.00) printf("Obese");

    return 0;
}
