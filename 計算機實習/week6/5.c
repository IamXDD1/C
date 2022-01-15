#include <stdio.h>
#include <stdlib.h>

int reverse(int number);

int main()
{
    int num = 0;
    scanf("%d", &num);

    printf("%d", reverse(num));
    return 0;
}

int reverse(int number){
    int temp = 0;
    for(;number != 0; number/=10)
    {
        temp *= 10;
        temp += number%10;
    }
    return temp;
}