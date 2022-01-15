#include <stdio.h>
#include <stdlib.h>

int random_num();
int random_output();

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
            else
            {
                switch(random_output()){
                    case 1: printf("No, Please try again.\n");  break;
                    case 2: printf("Wrong. Try once more.\n");  break;
                    case 3: printf("Don’t give up.\n");         break;
                    case 4: printf("No. Keep trying.\n");       break;
                }
            }
        }
        switch(random_output()){
            case 1: printf("Very good!\n");             break;
            case 2: printf("Excellent!\n");             break;
            case 3: printf("Nice work!\n");             break;
            case 4: printf("Keep up the good work!\n"); break;
        }
    }

    return 0;
}
int random_num(){
    return rand()%10;
}
int random_output(){
    return rand()%4+1;
}