#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* fact_calc(int n, char* str_res){

    char temp[10] = "";

    temp[0] = '0'+n;
    strcat(str_res, temp);
    strcat(str_res, "!=");



    int count = 1;
    for(int i=n; i>0; i--)
    {
        count *= i;

        temp[0] = '0'+i;
        strcat(str_res, temp);
        if(i != 1) strcat(str_res, "x");
        else strcat(str_res, "=");
    }

    int len = 0;
    for(int i=0;count != 0; count /= 10, i++)
    {
        temp[i] = '0' + count%10;
        len++;
    }

    for(int i=0; i<len/2;i++)
    {
        char tmp = temp[i];
        temp[i] = temp[len-i-1];
        temp[len-i-1] = tmp;
    }

    strcat(str_res, temp);
    return str_res;
}

int main()
{
    int input;

    for(;scanf("%d", &input);)
    {
        char str_res[100] = "";
        if(input == -1) break;

        if(input >= 0 && input <= 9)
        {
            char* output = fact_calc(input, str_res);


            int n = strlen(output)+2;
            for(int i=0; i<n; i++) printf("*");
            printf("\n*%s*\n", output);
            for(int i=0; i<n; i++) printf("*");
            printf("\n");
        }
        else
        {
            printf("Invalid entry\n");
        }
    }
    return 0;
}