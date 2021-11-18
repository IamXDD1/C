#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Encoding[12][5] = {{1,0,0,0,0},{1,0,0,1,0},{0,0,0,1,1},{1,0,1,0,0},
                       {0,1,1,0,0},{1,1,0,0,0},{0,0,1,0,1},{0,1,0,0,1},
                       {1,0,0,0,1},{0,0,0,0,1},{0,0,1,0,0},{0,0,1,1,0}};

enum Status {RUN, SKIP};
char decode(int* arr, int curr);
int mass_num(int* arr);
_Bool check_C(char* code, char C);
_Bool check_K(char* code, char C, char K);
int check_out_of_range(int num, double intended);
int check_start_end_success(int* arr, int size);

int main()
{
    //輸入20組 (fread)
    for(int size = 0, x=1; scanf("%d", &size);x++)
    {
        enum Status game = RUN;

        if(size == 0) break;
        printf("Case %d: ", x);

        if((size+1)%6 != 0){
            printf("bad code\n");
            game = SKIP;
        }

        if(game != SKIP)
        {
            //輸入寬度 (fread)
            int arr_num_appear[200] = {};
            int arr_width[size];
            for(int i=0, input=0; i<size; i++)
            {
                scanf("%d", &input);
                arr_width[i] = input;
                arr_num_appear[input-1]++;
            }

            int intended = mass_num(arr_num_appear);

            int Decoded_num_size = (size+1)/6;
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
                int begin_to_end = check_start_end_success(arr_width, size);

                if(begin_to_end == 1){
                    //begin to end

                    //01轉字元
                    char C,K;
                    for(int i=6, j=0; i<size; i+=6, j++){

                        if(j == Decoded_num_size) C = decode(arr_width, i);
                        else if(j == Decoded_num_size+1) K = decode(arr_width, i);
                        else if(j == Decoded_num_size+2) break;
                        else Decoded_num[j] = decode(arr_width, i);
                    }
                    //判斷CK
                    if(check_C(Decoded_num, C)){
                        game = SKIP;
                        printf("bad C\n");
                    }
                    else if(check_K(Decoded_num, C, K)){
                        game = SKIP;
                        printf("bad K\n");
                    }
                }
                else if(begin_to_end == 2){
                    //end to begin
                    //======================================施工中===================================================
                    char C,K;
                    for(int i=6, j=0; i<size; i+=6, j++){

                        if(j == Decoded_num_size) C = decode(arr_width, i);
                        else if(j == Decoded_num_size+1) K = decode(arr_width, i);
                        else if(j == Decoded_num_size+2) break;
                        else Decoded_num[j] = decode(arr_width, i);
                    }
                    //判斷CK
                    if(check_C(Decoded_num, C)){
                        game = SKIP;
                        printf("bad C\n");
                    }
                    else if(check_K(Decoded_num, C, K)){
                        game = SKIP;
                        printf("bad K\n");
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

char decode(int* arr, int curr){
    for(int j=0; j<12; j++)
    {
        for(int i=0; i<5; i++)
        {
            if(arr[curr+i] != Encoding[j][i]) break;

            if(i==4){
                if(j != 10) return '0'+j;
                else return '-';
            }
        }
    }
}
int mass_num(int* arr){
    int num = 0;
    int count = 0;
    for(int i=0; i<200; i++)
    {
        if(arr[i] > count) {
            num = i+1;
            count = arr[i];
        }
    }
    return num;
}
_Bool check_C(char* code, char C){
    int sum = 0;
    int n = strlen(code);
    for(int i=1; i<=n; i++)
    {
        int temp = 0;
        if(code[i-1] == '-') temp = 10;
        else temp = code[i-1] - '0';

        sum += ((n-i)%10+1)*temp;
    }
    sum %= 11;
    if(C == '-') C = '9'+1;

    if(sum == C-'0') return 0;
    else return 1;
}
_Bool check_K(char* code, char C, char K){
    int sum = 0;
    int n = strlen(code);
    for(int i=1; i<=n; i++)
    {
        int temp = 0;
        if(code[i-1] == '-') temp = 10;
        else temp = code[i-1] - '0';

        sum += ((n-i)%9+1)*temp;
    }
    if(C == '-') sum += 10;
    if(K == '-') K = '9'+1;
    sum %= 11;

    if(sum == K-'0') return 1;
    else return 0;
}
int check_out_of_range(int num, double intended){
    if(num >= intended*0.95 && num <= intended*1.05) return 1;
    else if(num >= intended*1.9 && num <= intended*2.1) return 2;
    else return 0;
}
int check_start_end_success(int* arr, int size){
    _Bool left_to_right = 1;
    _Bool right_to_left = 1;
    for(int i=0; i<5; i++)
    {
        if(Encoding[11][i] != arr[i]){
            left_to_right = 0;
            break;
        }
    }
    if(left_to_right){
        for(int i=0; i<5; i++)
        {
            if(Encoding[11][i] != arr[size-5+i]){
                left_to_right = 0;
                break;
            }
        }
    }
    if(left_to_right == 0){
        for(int i=0; i<5; i++)
        {
            if(Encoding[11][i] != arr[size-i-1]){
                right_to_left = 0;
                break;
            }
        }
        if(right_to_left){
            for(int i=0; i<5; i++)
            {
                if(Encoding[11][i] != arr[4-i]){
                    right_to_left = 0;
                    break;
                }
            }
        }
    }

    if(left_to_right) return 1;
    else if(right_to_left) return 2;
    else return 0;
}
