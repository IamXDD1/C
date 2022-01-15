#include <stdio.h>
#include <stdlib.h>

typedef struct fraction{
    int numerator;
    int denominator;
}fraction;

int GCD(int a, int b){
    if(a == 0)
        return b;
    else{
        return GCD(b%a, a);
    }
}

void reduce(fraction f, fraction* reduced_f){
    int temp = GCD(f.numerator, f.denominator);

    reduced_f->numerator = f.numerator / temp;
    reduced_f->denominator = f.denominator / temp;
}

int main()
{
    fraction f, Ans;
    scanf("%d/%d", &f.numerator, &f.denominator);

    reduce(f, &Ans);

    printf("%d/%d", Ans.numerator, Ans.denominator);
    return 0;
}