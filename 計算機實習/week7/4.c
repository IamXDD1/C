#include <stdio.h>
#include <stdlib.h>

int LCM(int num1, int num2)
{
    if(num2 % num1 == 0) return num1;
    else return LCM(num2%num1, num1);
}

int main()
{
    int num1=0, num2=0;
    scanf("%d %d", &num1, &num2);
    printf("%d", num1*num2/LCM(num1, num2));
    return 0;
}