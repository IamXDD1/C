#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number1;
    int number2;

    printf("Enter two numbers\nnumber1¡G");
    scanf("%d", &number1);

    printf("number2¡G");
    scanf("%d", &number2);

    printf("\nsum = %d", number1 + number2);
    printf("\nproduct = %d", number1 * number2);
    printf("\ndifference = %d", number1 - number2);
    printf("\nquotient = %d", number1 / number2);
    printf("\nremainder = %d", number1 % number2);
}
