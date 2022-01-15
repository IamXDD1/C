#include <stdio.h>
#include <stdlib.h>

int roll_dice(){return rand()%6;}

int main()
{
    srand(48763);
    printf("%d\n", 48763);

    int arr[36] = {0};

    for(int i=0; i<36000; i++){
        int num1 = roll_dice();  //0~5
        int num2 = roll_dice();
        arr[num1*6+num2]++;
    }

    for(int i=1; i<=36; i++)
    {
        printf("%d ", arr[i-1]);
        if(i%6 == 0 && i!=36) printf("\n");
    }

    return 0;
}