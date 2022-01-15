#include <stdio.h>
#include <stdlib.h>

int random_num(){return rand()%10;}
int random_output(){return rand()%4;}
int random_question();
int problem_plus();
int problem_minus();
int problem_times();

int main()
{
    srand(48763);

    int level;
    scanf("%d", &level);

    for(int i=0; i<10; i++)
    {
        int Ans = 0;

        switch(level){
            case 1: Ans = problem_plus();     break;
            case 2: Ans = problem_minus();    break;
            case 3: Ans = problem_times();    break;
            case 4: Ans = random_question();  break;
        }

        for(;;)
        {
            int calculate = 0;
            scanf("%d", &calculate);

            if(calculate == Ans) break;
            else
            {
                switch(random_output()){
                    case 0: printf("No, Please try again.\n");  break;
                    case 1: printf("Wrong. Try once more.\n");  break;
                    case 2: printf("Don’t give up.\n");         break;
                    case 3: printf("No. Keep trying.\n");       break;
                }
            }
        }
        switch(random_output()){
            case 0: printf("Very good!\n");             break;
            case 1: printf("Excellent!\n");             break;
            case 2: printf("Nice work!\n");             break;
            case 3: printf("Keep up the good work!\n"); break;
        }
    }

    return 0;
}

int random_question(){
    switch(rand()%3){
        case 0: return problem_plus();
        case 1: return problem_minus();
        case 2: return problem_times();
    }
}
int problem_plus(){
    int num1 = random_num();
    int num2 = random_num();
    printf("How much is %d plus %d?\n", num1, num2);
    
    return num1+num2;
}
int problem_minus(){
    int num1 = random_num();
    int num2 = random_num();
    printf("How much is %d minus %d?\n", num1, num2);
    
    return num1-num2;
}
int problem_times(){
    int num1 = random_num();
    int num2 = random_num();
    printf("How much is %d times %d?\n", num1, num2);
    
    return num1*num2;
}