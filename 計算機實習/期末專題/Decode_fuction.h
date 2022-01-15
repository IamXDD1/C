#ifndef DECODE_FUCTION_H_INCLUDED
#define DECODE_FUCTION_H_INCLUDED
#include <string.h>

int Encoding[12][5] = {{1,0,0,0,0},{1,0,0,1,0},{0,0,0,1,1},{1,0,1,0,0}, //now
                       {0,1,1,0,0},{1,1,0,0,0},{0,0,1,0,1},{0,1,0,0,1},
                       {1,0,0,0,1},{0,0,0,0,1},{0,0,1,0,0},{0,0,1,1,0}};

/*
int Encoding[12][5] = {{0,0,0,0,1},{1,0,0,0,1},{0,1,0,0,1},{1,1,0,0,0}, //senpai
                       {0,0,1,0,1},{1,0,1,0,0},{0,1,1,0,0},{0,0,0,1,1},
                       {1,0,0,1,0},{1,0,0,0,0},{0,0,1,0,0},{0,0,1,1,0}};
*/

char decode(int* arr, int curr, _Bool left_to_right){
    if(left_to_right)
    {
        for(int j=0; j<12; j++)
        {
            for(int i=0; i<5; i++)
            {
                if(arr[curr+i] != Encoding[j][i]) break;

                if(i==4){
                    //printf("\nj=%d  %d%d%d%d%d¡G",j,arr[curr],arr[curr+1],arr[curr+2],arr[curr+3],arr[curr+4]);

                    if(j != 10) return '0'+j;
                    else return '-';
                }
            }
        }
    }
    else
    {
        for(int j=0; j<12; j++)
        {
            for(int i=0; i<5; i++)
            {
                if(arr[curr-i] != Encoding[j][i]) break;

                if(i==4){
                    //printf("\nj=%d  %d%d%d%d%d¡G",j,arr[curr],arr[curr-1],arr[curr-2],arr[curr-3],arr[curr-4]);

                    if(j != 10) return '0'+j;
                    else return '-';
                }
            }
        }
    }
    return 'X';
}
int mass_num(int* arr){
    int num = 0;
    int bound = 0;
    _Bool bound_set = 0;
    int count = 0;
    for(int i=0; i<200; i++)
    {
        if(arr[i] > count) {
            if(bound_set == 0){
                bound_set = 1;
                bound = (i+1)*2-15;
                num = i+1;
            }
            if(i < bound){
                num = i+1;
                count = arr[i];
            }
        }
    }
    //基準值可能不會出現 ex:只出現35、37 但基準是36 -> 可以取(35+37)/2 ?(未知)
    return num;
}
_Bool check_C(char* code, char C, int str_length){
    int sum = 0;

    for(int i=1; i<=str_length; i++)
    {
        int temp = 0;
        if(code[i-1] == '-') temp = 10;
        else temp = code[i-1] - '0';

        sum += ((str_length-i)%10+1)*temp;
    }
    sum %= 11;
    if(C == '-') C = '9'+1;

    if(sum == C-'0') return 0;
    else return 1;
}
_Bool check_K(char* code, char C, char K, int str_length){
    int sum = 0;

    for(int i=1; i<=str_length; i++)
    {
        int temp = 0;
        if(code[i-1] == '-') temp = 10;
        else temp = code[i-1] - '0';

        sum += ((str_length-i+1)%9+1)*temp;

    }
    if(C == '-') sum += 10;
    else sum += C - '0';
    if(K == '-') K = '9'+1;
    sum %= 11;

    if(sum == K-'0') return 0;
    else return 1;
}
int check_out_of_range(int num, double intended){
    if(num >= intended*0.95 && num <= intended*1.05) return 1;
    else if(num >= intended*1.9 && num <= intended*2.1) return 2;
    else{
        return 0;
    }
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


#endif // DECODE_FUCTION_H_INCLUDED
