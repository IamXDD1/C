#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Decode_fuction.h"

enum Status {RUN, SKIP};

int main()
{
    //��J20�� (fread)
    for(int size = 0, x=1; scanf("%d", &size);x++)
    {
        enum Status game = RUN;

        if(size == 0) break;
        printf("Case %d: ", x);

        //��J�e�� (fread)
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
                //======================================�I�u��===================================================
                //�[�Wbad code�G decode function �p�G�����S���^�� �h��Xbad code �B���X�B�@
                int begin_to_end = check_start_end_success(arr_width, size);

                if(begin_to_end == 1){
                    //begin to end

                    //01��r��
                    char C,K;
                    for(int i=6, j=0; i<size; i+=6, j++){

                        if(j == Decoded_num_size) C = decode(arr_width, i, 1);
                        else if(j == Decoded_num_size+1) K = decode(arr_width, i, 1);
                        else if(j == Decoded_num_size+2) break;
                        else Decoded_num[j] = decode(arr_width, i, 1);

                        //printf("%c %c %c", Decoded_num[j], C, K);
                    }
                    //�P�_CK
                    //�ץ��Gstrlen(decoded_num)�����D ���`size = 2 �X�ӫo�O6
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
                    //======================================�I�u��===================================================
                    char C,K;
                    for(int i=size-7, j=0; i>=6; i-=6, j++){

                        if(j == Decoded_num_size) C = decode(arr_width, i, 0);
                        else if(j == Decoded_num_size+1) K = decode(arr_width, i, 0);
                        else if(j == Decoded_num_size+2) break;
                        else Decoded_num[j] = decode(arr_width, i, 0);

                        //printf("%c", Decoded_num[j]);
                    }
                    //�P�_CK
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
                    //======================================�I�u��===================================================
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

