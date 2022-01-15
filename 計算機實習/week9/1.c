#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_arr1[5]={0};
    int num_arr2[5]={0};

    for(int i=0; i<5; ++i){
        scanf("%d", &num_arr1[i]);
    }
    for(int i=0,j=0; i<5; ++i){
        scanf("%d", &num_arr2[i]);
    }

    for(int i=0,j=0; i!=5 && j!=5; ){
        if(num_arr1[i] > num_arr2[j]) ++j;
        else if(num_arr1[i] < num_arr2[j]) ++i;
        else{
            printf("%d ", num_arr1[i]);
            ++i;
            ++j;
        }
    }
    return 0;
}