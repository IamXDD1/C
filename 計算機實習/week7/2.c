#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char guess_num(int num);

int main()
{
    srand(48763);
    for(;;)
    {
        if(guess_num(rand()%1000 +1) == 'n') break;
        else continue;
    }
    return 0;
}
char guess_num(int num){

    for(int input = 0; input != num;)
    {
        scanf("%d", &input);
        if(input > num) printf("High\n");
        else if(input < num) printf("Low\n");
    }
    printf("Congratulations\n");

    char yes_or_not = 'y';
    scanf(" %c", &yes_or_not);
    return yes_or_not;
}