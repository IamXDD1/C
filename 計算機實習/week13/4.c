#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct sci_not_t{
    double mantissa;
    int exponent;
}sci_not_t;

int check(double m){
    if(m >= 0.1 && m < 1) return 1;
    else if(m < 0.1) return 0;
    else return 2;
}

void scan_sci(sci_not_t* m1, sci_not_t* m2){
    char input[20] = "";
    scanf("%[^e]e%d", input, &m1->exponent);
    sscanf(input, "%lf", &m1->mantissa);

    char input2[20] = "";
    scanf("%[^e]e%d", input2, &m2->exponent);
    sscanf(input2, "%lf", &m2->mantissa);
}
void print_sci(sci_not_t* Ans){
    for(;check(Ans->mantissa) != 1;)
    {
        if(check(Ans->mantissa) == 0){
        Ans->mantissa *= 10;
        Ans->exponent -= 1;
        }

        if(check(Ans->mantissa) == 2){
            Ans->mantissa /= 10;
            Ans->exponent += 1;
        }
    }


    printf("%.5lfe%d\n", Ans->mantissa, Ans->exponent);
}

sci_not_t* sum(sci_not_t a, sci_not_t b, sci_not_t* Ans);
sci_not_t* difference(sci_not_t a, sci_not_t b, sci_not_t* Ans);
sci_not_t* product(sci_not_t a, sci_not_t b, sci_not_t* Ans);
sci_not_t* quotient(sci_not_t a, sci_not_t b, sci_not_t* Ans);

int main()
{
    sci_not_t m1, m2, Ans;

    scan_sci(&m1, &m2);

    for(;check(m1.mantissa) != 1;)
    {
        if(check(m1.mantissa) == 0){
            m1.mantissa *= 10;
            m1.exponent -= 1;
        }

        if(check(m1.mantissa) == 2){
            m1.mantissa /= 10;
            m1.exponent += 1;
        }
    }

    for(;check(m2.mantissa) != 1;)
    {
        if(check(m2.mantissa) == 0){
            m2.mantissa *= 10;
            m2.exponent -= 1;
        }

        if(check(m2.mantissa) == 2){
            m2.mantissa /= 10;
            m2.exponent += 1;
        }
    }

    if(m1.exponent > m2.exponent) Ans.exponent = m1.exponent;
    else Ans.exponent = m2.exponent;

    print_sci(sum(m1, m2, &Ans));
    print_sci(difference(m1, m2, &Ans));
    print_sci(product(m1, m2, &Ans));
    print_sci(quotient(m1, m2, &Ans));

    return 0;
}

sci_not_t* sum(sci_not_t a, sci_not_t b, sci_not_t* Ans){
    Ans->mantissa = (a.mantissa*pow(10, a.exponent) + b.mantissa*pow(10, b.exponent))/pow(10,Ans->exponent);
    return Ans;
}

sci_not_t* difference(sci_not_t a, sci_not_t b, sci_not_t* Ans){
    Ans->mantissa = (a.mantissa*pow(10, a.exponent) - b.mantissa*pow(10, b.exponent))/pow(10,Ans->exponent);
    return Ans;
}

sci_not_t* product(sci_not_t a, sci_not_t b, sci_not_t* Ans){
    Ans->mantissa = (a.mantissa*pow(10, a.exponent) * b.mantissa*pow(10, b.exponent))/pow(10,Ans->exponent);
    return Ans;
}

sci_not_t* quotient(sci_not_t a, sci_not_t b, sci_not_t* Ans){
    Ans->mantissa = ((a.mantissa*pow(10, a.exponent)) / (b.mantissa*pow(10, b.exponent))) / pow(10,Ans->exponent);
    return Ans;
}