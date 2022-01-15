#include <stdio.h>
#include <stdlib.h>

int isPerfect(int num);

int main()
{
    for(int i=1; i<=1000; i++)
    {
        if(isPerfect(i))
        {
            printf("%d ", i);
            for(int j=1; j<i; j++)
            {
                if(i%j == 0) printf("%d ", j);
            }
            printf("\n");
        }
    }
    return 0;
}

int isPerfect(int num){
    int sum = 0;
    for(int j=1; j<num; j++)
    {
        if(num%j == 0) sum += j;
    }

    if(sum == num) return 1;
    else return 0;
}