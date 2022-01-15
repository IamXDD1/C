#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    for(int count=0, Palindromic = 1, number = 2; count<120; number++, Palindromic = 1)
    {
        int nums[7] = {};

        int k=0;
        for(int i = number; i!=0 ; i /= 10, k++)
        {
            nums[k] = i%10;
        }

        for(int ct=0; ct < k/2; ct++)
        {
            if(nums[k-1-ct] == nums[ct]) continue;
            else Palindromic = 0;
        }

        if(Palindromic)
        {
            int check_prime = 1;
            for(int j=2; j<=sqrt(number); j++)
            {
                if(number % j == 0)
                {
                    check_prime = 0;
                    break;
                }
            }

            if(check_prime)
            {
                count++;
                printf("%d ", number);
                if(count % 10 == 0) printf("\n");
            }


        }
    }
    return 0;
}