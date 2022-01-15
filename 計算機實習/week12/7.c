#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[200];

    gets(input);

    char str[200];

    gets(str);

    char* temp = strstr(input, str);

    for(;temp != NULL; ){

        printf("%s\n", temp);

        temp = strstr(temp+1, str);
    }

    return 0;
}