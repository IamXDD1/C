#include<stdio.h>
#include<stdlib.h>

_Bool judge_lowercase(char input)
{
    if(input >= 'a' && input <= 'z')
        return 1;
    else
        return 0;
}

int main(){

    _Bool test = 2;
    printf("%d", test);
    return 0;
}
