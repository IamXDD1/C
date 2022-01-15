#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_race(char* race){
    for(int i=0; i<70; i++){
        printf("%c", race[i]);
    }
    printf("\n");
}
int T_move(int i){
    printf("T ");
    switch(i)
    {
        case 0 ... 4: printf("Fast plod\n"); return 3;
        case 5 ... 6: printf("Slip\n"); return -6;
        case 7 ... 9: printf("Slow plod\n"); return 1;
    }
    return 0;
}
int H_move(int i){
    printf("H ");
    switch(i)
    {
        case 0 ... 1: printf("Sleep\n"); return 0;
        case 2 ... 3: printf("Big hop\n"); return 9;
        case 4:       printf("Big slip\n"); return -12;
        case 5 ... 7: printf("Small hop\n"); return 1;
        case 8 ... 9: printf("Small slip\n"); return -2;
    }
    return 0;
}

int main()
{
    srand(time(NULL));
    printf("BANG !!!!!\n");
    printf("AND THEY'RE OFF !!!!!\n");

    _Bool end_game = 0;

    char race[70];

    for(int i=0; i<70; i++){
        race[i] = ' ';
    }

    int T_distance = 1;
    int H_distance = 1;

    for(;end_game == 0;)
    {
        T_distance += T_move(rand()%10);
        H_distance += H_move(rand()%10);

        if(T_distance < 1) T_distance = 1;
        if(H_distance < 1) H_distance = 1;

        race[T_distance-1] = 'T';
        race[H_distance-1] = 'H';


        if(T_distance == H_distance) printf("OUCH!!!");
        else print_race(race);

        if(T_distance >= 70 && H_distance >= 70){
            end_game = 1;
            printf("It's a tie.");
        }
        else if(T_distance >= 70){
            end_game = 1;
            printf("TORTOISE WINS!!! YAY!!!");
        }
        else if(H_distance >= 70){
            end_game = 1;
            printf("Hare wins. Yuch.");
        }

        race[T_distance-1] = ' ';
        race[H_distance-1] = ' ';
    }


    return 0;
}