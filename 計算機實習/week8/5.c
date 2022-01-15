#include <stdio.h>
#include <stdlib.h>

int random_num(){return rand()%10;}
int random_output(){return rand()%4+1;}

int main()
{
    srand(48763);
    int correct = 0;
    for(int i=0; i<10;)
    {
        int num1 = random_num();
        int num2 = random_num();

        printf("How much is %d times %d?\n", num1, num2);

        int Ans = num1*num2;
        for(;i<10;)
        {
            int calculate = 0;
            scanf("%d", &calculate);
            i++;

            if(calculate == Ans)
            {
                switch(random_output()){
                    case 1: printf("Very good!\n");             break;
                    case 2: printf("Excellent!\n");             break;
                    case 3: printf("Nice work!\n");             break;
                    case 4: printf("Keep up the good work!\n"); break;
                }
                correct+=1;
                break;
            }
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
    }
    if((double)correct/10 >= 0.75) printf("Congratulations, you are ready to go to the next level!");
    else printf("Please ask your teacher for extra help.");

    return 0;
}