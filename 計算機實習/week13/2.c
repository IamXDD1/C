#include <stdio.h>
#include <stdlib.h>

typedef struct complex_num{
    double real;
    double imaginary;
}complex_num;

complex_num* add_complex(complex_num a, complex_num b, complex_num* Ans){
    Ans->real = a.real + b.real;
    Ans->imaginary = a.imaginary + b.imaginary;

    return Ans;
}

int main()
{
    complex_num num1, num2, Ans;

    complex_num* Ans_ptr;

    scanf("%lf+%lfi", &num1.real, &num1.imaginary);
    scanf("%lf+%lfi", &num2.real, &num2.imaginary);

    Ans_ptr = add_complex(num1, num2, &Ans);

    printf("%.1lf+%.1lfi", Ans_ptr->real, Ans_ptr->imaginary);
    return 0;
}
