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

    char input = getchar();

    if(judge_lowercase(input)) printf("true");
    else printf("false");
    return 0;
}
