#include <stdio.h>
#include <stdlib.h>

long C(long top, long bot);

int main()
{
    long int num1,num2;
    scanf("%ld %ld", &num1, &num2);
    printf("%ld", C(num1, num2));

    return 0;
}
long C(long top, long bot){
    if(bot > 0 && top > bot)
        return C(top-1, bot) + C(top-1, bot-1);
    else
        return 1;

    return 1;
}