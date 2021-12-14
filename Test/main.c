#include <stdio.h>
#include <stdlib.h>
#include <time.h>

_Bool check[4][13] = {0};
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
int compare(char* char_cards);
void deal_5cards(int* cards);
void change(char* c_cards, int* i_cards);
void sort(char* c_cards);
int four_of_a_kind(char* c_cards);
int full_house(char* c_cards);
int flush(char* c_cards);
int straight(char* c_cards);
int three_of_a_kind(char* c_cards);
int two_pair(char* c_cards);
int one_pair(char* c_cards);


int main()
{
    srand(time(NULL));
    int p1_int_cards[5] = {0};
    char p1_char_cards[5][2];

    deal_5cards(p1_int_cards);

    p1_int_cards[0] = 5;
    p1_int_cards[1] = 20;
    p1_int_cards[2] = 46;
    p1_int_cards[3] = 52;
    p1_int_cards[4] = 13;

    change((char*)p1_char_cards, p1_int_cards);

    sort((char*)p1_char_cards);

    for(int i=0; i<5; i++){
        printf("%c%c ", p1_char_cards[i][0], p1_char_cards[i][1]);
    }
    printf("\n");

    int player1 = compare((char*)p1_char_cards);

    int p2_int_cards[5] = {0};
    char p2_char_cards[5][2];

    deal_5cards(p2_int_cards);

    p2_int_cards[0] = 18;
    p2_int_cards[1] = 31;
    p2_int_cards[2] = 22;
    p2_int_cards[3] = 39;
    p2_int_cards[4] = 26;

    change((char*)p2_char_cards, p2_int_cards);

    sort((char*)p2_char_cards);

    for(int i=0; i<5; i++){
        printf("%c%c ", p2_char_cards[i][0], p2_char_cards[i][1]);
    }
    printf("\n");

    int player2 = compare((char*)p2_char_cards);

    if(player1 < player2){
        for(int i=0; i<5; i++)
            printf("%c%c ", p1_char_cards[i][0], p1_char_cards[i][1]);
    }
    else if(player2 < player1){
        for(int i=0; i<5; i++)
            printf("%c%c ", p2_char_cards[i][0], p2_char_cards[i][1]);
    }
    else{
        for(int i=4; i>=0; i--){
            if(number(p1_char_cards[i][1]) > number(p2_char_cards[i][1])){
                for(int j=0; j<5; j++)
                    printf("%c%c ", p1_char_cards[j][0], p1_char_cards[j][1]);
                break;
            }
            else if(number(p1_char_cards[i][1]) < number(p2_char_cards[i][1])){
                for(int j=0; j<5; j++)
                    printf("%c%c ", p2_char_cards[j][0], p2_char_cards[j][1]);
                break;
            }
        }
    }

    return 0;
}

int compare(char* char_cards){
    int check = 0;
    for(int i=0; i<7; i++){
        switch(i)
        {
            case 0: check = four_of_a_kind(char_cards); if(check){printf("Four of a kind\n"); return 0-check;}       break;
            case 1: check = full_house(char_cards);     if(check){printf("Full house\n"); return 20-check;}          break;
            case 2: check = flush(char_cards);          if(check){printf("Flush\n"); return 40-check;}               break;
            case 3: check = straight(char_cards);       if(check){printf("Straight\n"); return 60-check;}            break;
            case 4: check = three_of_a_kind(char_cards);if(check){printf("Three of a kind\n"); return 80-check;}     break;
            case 5: check = two_pair(char_cards);       if(check){printf("Two pair\n"); return 100-check;}           break;
            case 6: check = one_pair(char_cards);       if(check){printf("One pair\n"); return 120-check;}           break;
        }

        if(check) break;
    }

    if(check == 0){
        printf("High card\n");
        return 140;
    }
}

void deal_5cards(int* cards){

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

int four_of_a_kind(char* c_cards){
    if(*(c_cards+1) == *(c_cards+7) || *(c_cards+3) == *(c_cards+9)) return number(*(c_cards+3));
    return 0;
}

int full_house(char* c_cards){
    if((*(c_cards+1) == *(c_cards+5) && *(c_cards+7) == *(c_cards+9))
    || (*(c_cards+9) == *(c_cards+5) && *(c_cards+1) == *(c_cards+3))) return number(*(c_cards+5));

    return 0;
}

int flush(char* c_cards){
    for(int i=0; i<4; i++)
    {
        if(*(c_cards+i*2) != *(c_cards+(i+1)*2)) return 0;
    }
    return number(*(c_cards+9));
}

int straight(char* c_cards){
    for(int i=0; i<4; i++)
    {
        int temp1 = number(*(c_cards+i*2+1));
        int temp2 = number(*(c_cards+(i+1)*2+1));
        if(temp1+1 != temp2) return 0;
    }
    return number(*(c_cards+9));
}
int three_of_a_kind(char* c_cards){
    if(*(c_cards+1) == *(c_cards+5) ||
       *(c_cards+5) == *(c_cards+9)) return number(*(c_cards+5));
    else if(*(c_cards+3) == *(c_cards+7)) return number(*(c_cards+3));

    return 0;
}
int two_pair(char* c_cards){
    int count = 0;
    int index = 0;
    for(int i=0; i<4; i++)
    {
        int temp1 = number(*(c_cards+i*2+1));
        int temp2 = number(*(c_cards+(i+1)*2+1));

        if(temp1 == temp2){
            count++;
            index = i;
        }
    }
    if(count == 2) return number(*(c_cards+(index)*2+1));
    return 0;
}

int one_pair(char* c_cards){
    int count = 0;
    int index = 0;
    for(int i=0; i<4; i++)
    {
        int temp1 = number(*(c_cards+i*2+1));
        int temp2 = number(*(c_cards+(i+1)*2+1));

        if(temp1 == temp2){
            count++;
            index = i;
        }
    }
    if(count == 1) return number(*(c_cards+(index)*2+1));
    return 0;
}
