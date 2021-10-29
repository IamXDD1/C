#include <stdio.h>

int main(){

//  for( 初始值 ; 條件式 ; 更新值 )
//  for( ; ; )
//10 9 8
// 1 2 3 4 5

    for(int n=1, k=10; n <= 10; n++, k--)
    {
        for(int n=1; n<11-k; n++)
        {
            printf(" ");
        }

        for(int n=1; n<=k; n++)
        {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}

