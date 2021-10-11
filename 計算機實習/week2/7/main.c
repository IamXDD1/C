#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1 = 0, num2 = 0;

    scanf("%d %d", &num1, &num2);

    if(num1 % num2 == 0) printf("Yes");
    else printf("No");

    return 0;
}
