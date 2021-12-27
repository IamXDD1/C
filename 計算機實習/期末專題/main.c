#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Decode_fuction.h"

enum Status {RUN, SKIP};

int main()
{
    FILE* file;

    if((file = fopen("00.test.txt","r")) == NULL)
    {
        printf("File could'n be opened.\n");
    }
    else
    {
        for(int size = 0, x=1; fscanf(file, "%d", &size);x++)
        {
            enum Status game = RUN;

            if(size == 0) break;

            //輸入寬度 (fread)
            _Bool range_of_input = 0;
            int arr_num_appear[200] = {};
            int arr_width[size];
            for(int i=0, input=0; i<size; i++)
            {
                fscanf(file, "%d", &input);
                arr_width[i] = input;
                if(input <= 200 && input >= 1) arr_num_appear[input-1]++;
                else range_of_input = 1;
            }

            int Decoded_num_size = (size+1)/6-4;

            if((size+1)%6 != 0 || Decoded_num_size <= 0 || size > 150 || range_of_input){
                printf("Case %d:bad code\n", x);
                game = SKIP;
            }

            if(game != SKIP)
            {
                int intended = mass_num(arr_num_appear);

                char Decoded_num[Decoded_num_size];

                //width to 0 or 1
                _Bool run_decode = 1;
                for(int i=0; i<size; i++)
                {
                    int range = check_out_of_range(arr_width[i], (double)intended);
                    if(range == 0){
                        game = SKIP;
                        printf("Case %d:bad code\n", x);
                        run_decode = 0;
                        break;
                    }
                    else if(range == 1){
                        arr_width[i] = 0;
                    }
                    else arr_width[i] = 1;
                }

                if(run_decode){
                    //======================================施工中===================================================
                    int begin_to_end = check_start_end_success(arr_width, size);
                    int str_length = 0;

                    if(begin_to_end == 1){
                        //begin to end

                        //01轉字元
                        char C = '0', K = '0';

                        for(int i=6, j=0; i<size; i+=6, j++){

                            if(j == Decoded_num_size) C = decode(arr_width, i, 1);
                            else if(j == Decoded_num_size+1) K = decode(arr_width, i, 1);
                            else if(j == Decoded_num_size+2) break;
                            else{
                                str_length++;
                                Decoded_num[j] = decode(arr_width, i, 1);
                            }

                            if(Decoded_num[j] == ';' || C == ';' || K == ';'){
                                game = SKIP;
                                printf("Case %d:bad code\n", x);
                                break;
                            }
                            if(Decoded_num[j] == 'X' || C == 'X' || K == 'X'){
                                game = SKIP;
                                printf("Case %d:bad code\n", x);
                                break;
                            }
                            //printf("%c %c %c\n", Decoded_num[j], C, K);
                        }
                        //判斷CK
                        if(game != SKIP)
                        {
                            if(check_C(Decoded_num, C, str_length)){
                                game = SKIP;
                                printf("Case %d:bad C\n", x);
                            }
                            else if(check_K(Decoded_num, C, K, str_length)){
                                game = SKIP;
                                printf("Case %d:bad K\n", x);
                            }
                        }


                    }
                    else if(begin_to_end == 2){
                        //end to begin
                        //======================================施工中===================================================
                        char C = '0',K = '0';
                        for(int i=size-7, j=0; i>=6; i-=6, j++){

                            if(j == Decoded_num_size) C = decode(arr_width, i, 0);
                            else if(j == Decoded_num_size+1) K = decode(arr_width, i, 0);
                            else if(j == Decoded_num_size+2) break;
                            else{
                                    str_length++;
                                    Decoded_num[j] = decode(arr_width, i, 0);
                            }

                            if(Decoded_num[j] == ';' || C == ';' || K == ';'){
                                game = SKIP;
                                printf("Case %d:bad code\n", x);
                                break;
                            }
                            //printf("%c", Decoded_num[j]);
                        }
                        //判斷CK
                        if(game != SKIP)
                        {
                            if(check_C(Decoded_num, C, str_length)){
                                game = SKIP;
                                printf("Case %d:bad C\n", x);
                            }
                            else if(check_K(Decoded_num, C, K, str_length)){
                                game = SKIP;
                                printf("Case %d:bad K\n", x);
                            }
                        }
                        //======================================施工中===================================================
                    }
                    else{
                        game = SKIP;
                        printf("Case %d:bad code\n", x);
                    }
                }

                if(game != SKIP){
                    //print code
                    printf("Case %d:", x);
                    for(int i=0; i<Decoded_num_size; i++)
                        printf("%c", Decoded_num[i]);
                    printf("\n");
                }
            }
        }
    }
    fclose(file);
    return 0;
}

