#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int flip();

int main()
{
    srand(48763);
    int heads = 0, tails = 0;
    for(int i=0; i<1000; i++)
    {
        if(flip() == 1)
        {
            printf("Heads\n");
            heads++;
        }
        else
        {
            printf("Tails\n");
            tails++;
        }
    }
    printf("%d %d", tails, heads);
    return 0;
}

int flip(){
    return rand()%2;
}