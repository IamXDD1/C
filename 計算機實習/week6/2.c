#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int discriminant(double a, double b, double c);
void calculate_roots(double a, double b, double c);

int main()
{
    double a=0, b=0, c=0;

    scanf("%lf %lf %lf", &a, &b, &c);

    if(discriminant(a, b, c)) calculate_roots(a, b, c);
    else printf("-1");


    return 0;
}

int discriminant(double a, double b, double c){
    if(b*b - 4*a*c >= 0) return 1;
    else return 0;
}
void calculate_roots(double a, double b, double c){

    printf("%.2lf %.2lf", (-b + sqrt(b*b-4*a*c)) / (a*2), (-b - sqrt(b*b-4*a*c)) / (a*2));
}