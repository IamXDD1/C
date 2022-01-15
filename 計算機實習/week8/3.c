#include <stdio.h>
#include <stdlib.h>

int random_num();

int main()
{
    srand(48763);
    for(int i=0; i<10; i++)
    {
        int num1 = random_num();
        int num2 = random_num();

        printf("How much is %d times %d?\n", num1, num2);

        int Ans = num1*num2;
        for(;;)
        {
            int calculate = 0;
            scanf("%d", &calculate);

            if(calculate == Ans) break;
            else printf("No, Please try again.\n");
        }

        printf("Very good!\n");
    }

    return 0;
}
int random_num(){
    return rand()%10;
}