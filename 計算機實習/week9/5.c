#include <stdio.h>
#include <stdlib.h>

int random_direct(){return rand()%2;}

int main()
{
    srand(4823);
    int balls = 0;
    int slots_num = 0;

    scanf("%d%d", &balls, &slots_num);
    int slots[slots_num];

    for(int i=0; i<slots_num; ++i) slots[i] = 0;

    int max = 0;
    for(int x=0; x<balls; x++){
        int count = 0;

        for(int times=1; times<slots_num; ++times)
        {
            if(random_direct() == 0){
                printf("L");
            }
            else{
                ++count;
                printf("R");
            }
        }

        ++slots[count];
        if(slots[count] > max) max = slots[count];

        printf("\n");
    }

    for(;max > 0; --max)
    {
        for(int i=0; i<slots_num; i++){
            if(slots[i] == max){
                --slots[i];
                printf("o");
            }
            else printf(" ");
        }
        printf("\n");
    }

    return 0;
}