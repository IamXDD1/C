include <stdio.h>
#include <stdlib.h>

void shuffle(int* deck){
    _Bool check[4][13] = {0};

    int row = 0;
    int col = 0;

    for(int i=0; i<4; i++){
        for(int j=0; j<13; j++){
            row = rand()%4;
            col = rand()%13;

            if(check[i][j] == 0){
                int temp = *(deck+i*13+j);
                *(deck+i*13+j) = *(deck+row*13+col);
                *(deck+row*13+col) = temp;
            }

            check[i][j] = 1;
            check[row][col] = 1;
        }
    }

}

int main()
{
    int deck[4][13] = {0};

    for(int i=0, count=1; i<4; i++){
        for(int j=0; j<13; j++,count++){
            deck[i][j] = count;
        }
    }

    shuffle((int*)deck);

    for(int i=0, count=1; i<4; i++){
        for(int j=0; j<13; j++,count++){
            printf("%d ", deck[i][j]);
        }
        printf("\n");
    }
    return 0;
}