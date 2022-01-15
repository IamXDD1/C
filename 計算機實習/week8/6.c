#include <stdio.h>
#include <stdlib.h>

int random_num_l1(){return rand()%10;}
int random_num_l2(){return rand()%100;}
int random_num_l3(){return rand()%1000;}
int random_output(){return rand()%4+1;}

int main()
{
    srand(48763);

    int level;
    scanf("%d", &level);

    for(int i=0; i<10; i++)
    {
        int num1=0, num2=0;
        switch(level){
            case 1: num1 = random_num_l1(); num2 = random_num_l1();  break;
            case 2: num1 = random_num_l2(); num2 = random_num_l2();  break;
            case 3: num1 = random_num_l3(); num2 = random_num_l3();  break;
        }

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