#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Decode_fuction.h"

enum Status {RUN, SKIP};

int main()
{
    //輸入20組 (fread)
    for(int size = 0, x=1; scanf("%d", &size);x++)
    {
        enum Status game = RUN;

        if(size == 0) break;
        printf("Case %d: ", x);

        //輸入寬度 (fread)
        int arr_num_appear[200] = {};
        int arr_width[size];
        for(int i=0, input=0; i<size; i++)
        {
            scanf("%d", &input);
            arr_width[i] = input;
            arr_num_appear[input-1]++;
        }

        int Decoded_num_size = (size+1)/6-4;

        if((size+1)%6 != 0 || Decoded_num_size <= 0){
            printf("bad code\n");
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
                    printf("bad code\n");
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
                //加上bad code： decode function 如果中間沒有回傳 則輸出bad code 且跳出運作
                int begin_to_end = check_start_end_success(arr_width, size);

                if(begin_to_end == 1){
                    //begin to end

                    //01轉字元
                    char C,K;
                    for(int i=6, j=0; i<size; i+=6, j++){

                        if(j == Decoded_num_size) C = decode(arr_width, i, 1);
                        else if(j == Decoded_num_size+1) K = decode(arr_width, i, 1);
                        else if(j == Decoded_num_size+2) break;
                        else Decoded_num[j] = decode(arr_width, i, 1);

                        //printf("%c %c %c", Decoded_num[j], C, K);
                    }
                    //判斷CK
                    //修正：strlen(decoded_num)有問題 正常size = 2 出來卻是6
                    if(check_C(Decoded_num, C)){
                        game = SKIP;
                        printf("bad C\n");
                    }
                    else{
                        if(check_K(Decoded_num, C, K)){
                            game = SKIP;
                            printf("bad K\n");
                        }
                    }

                }
                else if(begin_to_end == 2){
                    //end to begin
                    //======================================施工中===================================================
                    char C,K;
                    for(int i=size-7, j=0; i>=6; i-=6, j++){

                        if(j == Decoded_num_size) C = decode(arr_width, i, 0);
                        else if(j == Decoded_num_size+1) K = decode(arr_width, i, 0);
                        else if(j == Decoded_num_size+2) break;
                        else Decoded_num[j] = decode(arr_width, i, 0);

                        //printf("%c", Decoded_num[j]);
                    }
                    //判斷CK
                    if(check_C(Decoded_num, C)){
                        game = SKIP;
                        printf("bad C\n");
                    }
                    else{
                        if(check_K(Decoded_num, C, K)){
                            game = SKIP;
                            printf("bad K\n");
                        }
                    }
                    //======================================施工中===================================================
                }
                else{
                    game = SKIP;
                    printf("bad code\n");
                }
            }

            if(game != SKIP){
                //print code
                for(int i=0; i<Decoded_num_size; i++)
                    printf("%c", Decoded_num[i]);
            }
        }
    }
    return 0;
}

