#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int number(char num){
    switch(num)
    {
        case 'A': return 14;
        case '1' ... '9': return num-'0';
        case 'T': return 10;
        case 'J': return 11;
        case 'Q': return 12;
        case 'K': return 13;
    }
}
void deal_5cards(int* cards);
void change(char* c_cards, int* i_cards);
void sort(char* c_cards);
_Bool four_of_a_kind(char* c_cards);
_Bool full_house(char* c_cards);
_Bool flush(char* c_cards);
_Bool straight(char* c_cards);
_Bool three_of_a_kind(char* c_cards);
_Bool two_pair(char* c_cards);
_Bool one_pair(char* c_cards);

int main()
{
    srand(time(NULL));
    int int_cards[5] = {0};
    char char_cards[5][2];

    deal_5cards(int_cards);

    change((char*)char_cards, int_cards);

    sort((char*)char_cards);

    for(int i=0; i<5; i++){
        printf("%c%c ", char_cards[i][0], char_cards[i][1]);
    }
    printf("\n");

    _Bool check = 0;
    for(int i=0; i<7; i++){
        switch(i)
        {
            case 0: check = four_of_a_kind((char*)char_cards); if(check){printf("Four of a kind\n");}     break;
            case 1: check = full_house((char*)char_cards);     if(check){printf("Full house\n");}         break;
            case 2: check = flush((char*)char_cards);          if(check){printf("Flush\n");}              break;
            case 3: check = straight((char*)char_cards);       if(check){printf("Straight\n");}           break;
            case 4: check = three_of_a_kind((char*)char_cards);if(check){printf("Three of a kind\n");}    break;
            case 5: check = two_pair((char*)char_cards);       if(check){printf("Two pair\n");}           break;
            case 6: check = one_pair((char*)char_cards);       if(check){printf("One pair\n");}           break;
        }

        if(check) break;
    }

    if(check == 0) printf("High card\n");


    return 0;
}

void deal_5cards(int* cards){
    _Bool check[4][13] = {0};

    int row = 0;
    int col = 0;

    for(int i=0; i<5;){
        row = rand()%4;
        col = rand()%13;

        if(check[row][col] == 0){
            cards[i] = (row)*13 + (col+1);
            i++;
        }

        check[row][col] = 1;
    }
}

void change(char* c_cards, int* i_cards){

    for(int i=0; i<5; i++){
        switch((i_cards[i]-1)/13)
        {
            case 0: *(c_cards+i*2) = 'S'; break;
            case 1: *(c_cards+i*2) = 'H'; break;
            case 2: *(c_cards+i*2) = 'D'; break;
            case 3: *(c_cards+i*2) = 'C'; break;
        }

        int temp = (i_cards[i]-1)%13;
        switch(temp)
        {
            case 0: *(c_cards+i*2+1) = 'A'; break;
            case 1 ... 8: *(c_cards+i*2+1) = '0'+temp+1; break;
            case 9: *(c_cards+i*2+1) = 'T'; break;
            case 10: *(c_cards+i*2+1) = 'J'; break;
            case 11: *(c_cards+i*2+1) = 'Q'; break;
            case 12: *(c_cards+i*2+1) = 'K'; break;
        }


    }
}

void sort(char* c_cards){
    int temp1 = 0;
    int temp2 = 0;
    for(int i=4; i>=0; i--){
        for(int j=0; j<i; j++){

            temp1 = number(*(c_cards+j*2+1));
            temp2 = number(*(c_cards+(j+1)*2+1));
            if(temp1 > temp2){
                int temp = *(c_cards+j*2+1);
                *(c_cards+j*2+1) = *(c_cards+(j+1)*2+1);
                *(c_cards+(j+1)*2+1) = temp;
            }
        }
    }
}

_Bool four_of_a_kind(char* c_cards){
    if(*(c_cards+1) == *(c_cards+7) || *(c_cards+3) == *(c_cards+9)) return 1;
    return 0;
}

_Bool full_house(char* c_cards){
    if((*(c_cards+1) == *(c_cards+5) && *(c_cards+7) == *(c_cards+9))
    || (*(c_cards+9) == *(c_cards+5) && *(c_cards+1) == *(c_cards+3))) return 1;

    return 0;
}

_Bool flush(char* c_cards){
    for(int i=0; i<4; i++)
    {
        if(*(c_cards+i*2) != *(c_cards+(i+1)*2)) return 0;
    }
    return 1;
}

_Bool straight(char* c_cards){
    for(int i=0; i<4; i++)
    {
        int temp1 = number(*(c_cards+i*2+1));
        int temp2 = number(*(c_cards+(i+1)*2+1));
        if(temp1+1 != temp2) return 0;
    }
    return 1;
}
_Bool three_of_a_kind(char* c_cards){
    if(*(c_cards+1) == *(c_cards+5) ||
       *(c_cards+3) == *(c_cards+7) ||
       *(c_cards+5) == *(c_cards+9)) return 1;

    return 0;
}
_Bool two_pair(char* c_cards){
    int count = 0;
    for(int i=0; i<4; i++)
    {
        int temp1 = number(*(c_cards+i*2+1));
        int temp2 = number(*(c_cards+(i+1)*2+1));

        if(temp1 == temp2){
            count++;
        }
    }
    if(count == 2) return 1;
    return 0;
}

_Bool one_pair(char* c_cards){
    int count = 0;
    for(int i=0; i<4; i++)
    {
        int temp1 = number(*(c_cards+i*2+1));
        int temp2 = number(*(c_cards+(i+1)*2+1));

        if(temp1 == temp2){
            count++;
        }
    }
    if(count == 1) return 1;
    return 0;
}