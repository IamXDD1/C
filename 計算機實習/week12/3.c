#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[200];
    scanf("%s", str);

    int n = strlen(str);
    for(int i=0; i<n; i++)
    {
        if(str[i] == '(' || str[i] == ')' || str[i] == '-') str[i] = ' ';
    }

    char* area = strtok(str, " ");

    printf("%02d\n", atoi(area));

    area = strtok(NULL, " ");

    long number = (long)atoi(area)*10000;

    area = strtok(NULL, " ");

    number += (long)atoi(area);

    printf("%ld", number);

    return 0;
}