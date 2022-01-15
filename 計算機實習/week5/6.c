#include <stdio.h>
#include <stdlib.h>

int main()
{
    for(int input = 0, max = -27000000, count = 0; scanf("%d", &input);)
    {
        if(input == 0)
        {
            printf("%d\n%d", max, count);
            break;
        }

        if(input > max)
        {
            max = input;
            count = 1;
        }
        else if(input == max) count++;
    }
    return 0;
}