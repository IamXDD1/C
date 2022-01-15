#include <stdio.h>
#include <stdlib.h>

int isEven(int num);

int main()
{
    for(int input = 0; scanf("%d", &input);)
    {
        if(input == 0) break;

        printf("%d ", isEven(input));
    }
    return 0;
}

int isEven(int num){
    if(num%2 == 0) return 1;
    else return 0;
}