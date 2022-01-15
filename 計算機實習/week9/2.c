#include <stdio.h>
#include <stdlib.h>

int random_num(){return rand()%2;}

int main()
{
    int matrix[6][6]={0};

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            matrix[i][j] = random_num();
            if(matrix[i][j] == 1){
                matrix[i][5]++;
                ++matrix[5][j];
            }
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int Ans = 0;
    for(int i=0, temp = 0; i<5; i++) if(matrix[i][5] > temp) {
        temp = matrix[i][5];
        Ans = i;
    }
    printf("%d ", Ans);

    for(int i=0, temp = 0; i<5; i++) if(matrix[5][i] > temp) {
        temp = matrix[5][i];
        Ans = i;
    }
    printf("%d ", Ans);

    return 0;
}