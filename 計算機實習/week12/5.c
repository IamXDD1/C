#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[200];

    gets(input);

    char str[200] = "";
    char temp[200] = "";

    char* tokenptr = strtok(input, " ");

    for(;tokenptr != NULL; ){

        strcpy(temp, tokenptr);

        strcat(temp, " ");

        strcat(temp, str);

        strcpy(str, temp);

        tokenptr = strtok(NULL, " ");
    }

    printf("%s", str);

    return 0;
}