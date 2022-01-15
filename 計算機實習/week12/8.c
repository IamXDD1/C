#include <stdio.h>
#include <stdlib.h>

int main()
{
    char* articles[5] = {"the", "a", "one", "some" , "any"};
    char* noun[5] = {"boy", "girl", "dog", "town" , "car"};
    char* verb[5] = {"drove", "jumped", "ran", "walked" , "skipped"};
    char* preposition [5] = {"to", "from", "over", "under" , "on"};

    for(int i=0; i<20; i++)
    {
        char temp[100] = "";

        strcat(temp, articles[rand()%5]);
        strcat(temp, " ");

        strcat(temp, noun[rand()%5]);
        strcat(temp, " ");

        strcat(temp, verb[rand()%5]);
        strcat(temp, " ");

        strcat(temp, preposition[rand()%5]);
        strcat(temp, " ");

        strcat(temp, articles[rand()%5]);
        strcat(temp, " ");

        strcat(temp, noun[rand()%5]);
        strcat(temp, ".");

        temp[0] = toupper(temp[0]);

        printf("%s\n", temp);
    }


    return 0;
}