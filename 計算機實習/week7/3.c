#include <stdio.h>
#include <stdlib.h>

double power(double num, int expoential);

int main()
{
    double num=0;
    int exp=0;

    scanf("%lf %d", &num, &exp);
    printf("%.4lf", power(num, exp));

    return 0;
}

double power(double num, int expoential){
    double num_copy = num;
    for(int i=1; i<expoential; i++)
    {
        num *= num_copy;
    }
    return num;
}