#include <stdio.h>
#include <stdlib.h>

int main()
{
    int side1 = 0;
    int side2 = 0;
    int side3 = 0;

    scanf("%d %d %d", &side1, &side2, &side3);

    if(side1 + side2 > side3 && side1 + side3 > side2 && side3 + side2 > side1)
        printf("Yes");
    else
        printf("No");

    return 0;
}
