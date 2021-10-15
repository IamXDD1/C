#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 0;
    scanf("%d", &num);
    _Bool bl_check = 0;

    for(int i=2; i<= num/2; i++)
    {
        if(num%i == 0)
        {
            bl_check = 1;
            printf("No");
            break;
        }
    }
    if(bl_check == 0) printf("Yes");
    return 0;
}
