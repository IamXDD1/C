#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matrix_1_hor = 0, matrix_1_ver = 0;
    scanf("%d %d", &matrix_1_hor, &matrix_1_ver);

    int matrix_2_hor = matrix_1_ver, matrix_2_ver = 0;
    scanf("%d %d", &matrix_2_hor, &matrix_2_ver);

    int matrix1[matrix_1_hor][matrix_1_ver];
    int matrix2[matrix_2_hor][matrix_2_ver];
    int res[matrix_1_hor][matrix_2_ver];

    for(int i=0; i<matrix_1_hor; ++i){
        for(int j=0; j<matrix_2_ver; j++){
            res[i][j] = 0;
        }
    }

    for(int i=0; i<matrix_1_hor; ++i){
        for(int j=0; j<matrix_1_ver; j++){
            scanf("%d", &matrix1[i][j]);
        }
    }

    for(int i=0; i<matrix_2_hor; ++i){
        for(int j=0, input = 0; j<matrix_2_ver; j++){
            scanf("%d", &matrix2[i][j]);
        }
    }

    for(int i=0; i<matrix_1_hor; ++i){
        for(int j=0; j<matrix_2_ver; j++){
            for(int k=0; k<matrix_2_hor; k++)
            {
                res[i][j] += matrix1[i][k]*matrix2[k][j];
            }
        }
    }

    for(int i=0; i<matrix_1_hor; ++i){
        for(int j=0; j<matrix_2_ver; j++){
            printf("%d", res[i][j]);
          	if(j != matrix_2_ver-1) printf(" ");
        }
        if(i != matrix_1_hor-1) printf("\n");
    }

    return 0;
}