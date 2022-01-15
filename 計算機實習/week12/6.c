#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[200];

    gets(input);

    char* temp[6];

    for(int i=0; ;i++)
    {
        if(input[i] == '"'){
            input[i] = ' ';
            break;
        }
    }

    char* tokenptr = strtok(input, " ");

    for(int i=0;tokenptr != NULL; i++){
        temp[i] = tokenptr;
        tokenptr = strtok(NULL, " ");
    }

    for(int i=5; i>=0; i--)
    {
        for(int j=0; j<i; j++)
        {
            for(int x=0; x<4;)
            {
                if(temp[j][x] > temp[j+1][x])
                {
                    char* temp2 = temp[j];
                    temp[j] = temp[j+1];
                    temp[j+1] = temp2;
                    break;
                }
                else if(temp[j][x] == temp[j+1][x]) x++;
                else break;
            }

        }
    }

    printf("\"");
    for(int i=0; i<5; i++)
    {
        printf("%s\",\"", temp[i]);
    }
    printf("%s\"", temp[5]);


    return 0;
}