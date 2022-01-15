#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count = 0;
    for(int i=2; i<8; i++){
        for(int j=1; j<i; j++){
            printf("%d %d\n", j, i);
            count++;
        }
    }
    printf("%d", count);
    return 0;
}