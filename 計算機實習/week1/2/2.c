#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hours = 0;
    int minute = 0;
    int second = 0;
    printf("Enter the total time elapsed¡G");
    scanf("%d", &second);

    printf("converting to h:min:s...\n");

    minute = second / 60;
    second %= 60;

    hours = minute / 60;
    minute %= 60;

    printf("= %d¡G%d¡G%d", hours, minute, second);

    return 0;
}
