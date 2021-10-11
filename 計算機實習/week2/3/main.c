#include <stdio.h>
#include <stdlib.h>

int main()
{
    int five_digit_integer = 0;
    int part1 = 0, part2 = 0;

    scanf("%d", &five_digit_integer);

    part1 = five_digit_integer/1000;
    part2 = five_digit_integer%100;

    if(part2%10 == part1/10 && part2/10 == part1%10)
        printf("Yes");
    else
        printf("No");

    return 0;
}
