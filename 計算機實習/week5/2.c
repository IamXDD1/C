#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int num = 0;
    scanf("%d", &num);

    int n = sqrt(num);
    for(int i=2;i<= n;)
    {
        if(num%i == 0)
        {
            num /= i;
            printf("%d\n", i);
        }
        else i++;
    }
    if(num != 1) printf("%d", num);
    return 0;
}