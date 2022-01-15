#include <stdio.h>
#include <stdlib.h>
#include <string.h>

_Bool testPalindrome(char str[], int i, int j){
    if(i<j)
    {
        for(;str[i] == '.' || str[i] == ',' || str[i] == ' '; ++i);

        for(;str[j] == '.' || str[j] == ',' || str[j] == ' '; --j);

        if(tolower(str[i]) != tolower(str[j])) return 0;

        return testPalindrome(str, i+1, j-1);
    }
    else return 1;
}

int main()
{
    char str[200];

    gets(str);

    if(testPalindrome(str, 0, strlen(str)-1)) printf("True");
    else printf("False");

    return 0;
}