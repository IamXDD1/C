#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stringReverse(char str[], int i){

    if(i>=0)
    {
        printf("%c", str[i]);

        stringReverse(str, i-1);
    }
}

int main()
{
    char str[200];

    scanf("%s", str);

    stringReverse(str, strlen(str)-1);
    return 0;
}