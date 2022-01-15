#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Status {CONTINUE, WON, LOST};
int rolldices();

int main()
{
    srand(48763);
    enum Status game;

    for(int bankBalanc = 1000, wager = 0; bankBalanc > 0;)
    {
        scanf("%d", &wager);
        if(wager > bankBalanc) printf("Overflow\n");
        else
        {
            int sum = rolldices();
            int temp = 0;

            switch(sum)
            {
                case 7: case 11: game = WON; break;
                case 2: case 3: case 12: game = LOST; break;
                default:
                    game = CONTINUE;
                    temp = sum;
                    break;
            }
            for(;game == CONTINUE;)
            {
                sum = rolldices();
                if(sum == temp) game = WON;
                else if(sum == 7) game = LOST;
            }

            if(game == WON)
            {
                printf("Win\n");
                bankBalanc += wager;
            }
            else
            {
                bankBalanc -= wager;
                printf("Lose\n");
            }
            printf("%d\n", bankBalanc);
        }

    }
    printf("Busted");

    return 0;
}
int rolldices(){
    int dice1 = rand()%6+1;
    int dice2 = rand()%6+1;
    return dice1 + dice2;
}