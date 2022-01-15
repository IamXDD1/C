#include <stdio.h>
#include <stdlib.h>

int main()
{
    char char_arr[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    _Bool X_turn = 1;
    _Bool end_game = 0;
    for(int i=0; i<=9; i++){
        printf("-------------\n");
        printf("| %c | %c | %c |\n", char_arr[0], char_arr[1], char_arr[2]);
        printf("-------------\n");
        printf("| %c | %c | %c |\n", char_arr[3], char_arr[4], char_arr[5]);
        printf("-------------\n");
        printf("| %c | %c | %c |\n", char_arr[6], char_arr[7], char_arr[8]);
        printf("-------------\n\n");

        
        //judge
        for(int i=0; i<3; i++)
        {
            if(char_arr[i] == char_arr[i+3] && char_arr[i] == char_arr[i+6] && char_arr[i]!=' '){
                printf("%c player won.", char_arr[i]);
                end_game = 1;
                break;
            }
            else if(char_arr[i*3] == char_arr[i*3+1] && char_arr[i*3] == char_arr[i*3+2] && char_arr[i*3]!=' '){
                printf("%c player won.", char_arr[i*3]);
                end_game = 1;
                break;
            }
            else if((i==0 || i==2) && char_arr[i] == char_arr[8-i] && char_arr[i] == char_arr[4] && char_arr[i]!=' '){
                printf("%c player won.", char_arr[i]);
                end_game = 1;
                break;
            }
        }
      
        if(i == 9) break;
      
        if(end_game) break;

        int row = 0;
        int column = 0;
        if(X_turn){
            printf("Enter a row for player X:\n");
            scanf("%d", &row);
            printf("Enter a column for player X:\n");
            scanf("%d", &column);

            char_arr[row*3 + column] = 'X';
            X_turn = 0;
        }
        else{
            printf("Enter a row for player O:\n");
            scanf("%d", &row);
            printf("Enter a column for player O:\n");
            scanf("%d", &column);

            char_arr[row*3 + column] = 'O';
            X_turn = 1;
        }
    }
    if(end_game == 0) printf("draw.");
    return 0;
}