#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[800];

    gets(str);

    for(int i=0; i<3; i++)
    {
        char* temp[200];
        gets(temp);

        strcat(str, " ");

        strcat(str, temp);
    }

    char* tokenptr = strtok(str, " ");

    int count = 0;

    for(;tokenptr != NULL; count++){
        tokenptr = strtok(NULL, " ");
    }

    printf("%d", count);

    return 0;
}