#include <stdio.h>

int main(){

    int arr[7] = {};

    int count = 0;
    for(int i=2; count<120; i++)
    {
        int ct = 0;
        for(int j=i; j != 0; j/=10, ct++)
        {
            arr[ct] = j%10;
        }

        int palidrone_check = 1;
        for(int k = 0; k < ct/2; k++)
        {
            if(arr[k] != arr[ct-1-k])
            {
                palidrone_check = 0;
                break;
            }
        }

        if(palidrone_check == 1)
        {
            if(1)
            {
                for(int i=0; i<7; i++)
                    printf("%d", arr[i]);

                printf(" ");

                count++;
                if(count%10 == 0) printf("\n");
            }
        }
    }

    return 0;
}
