#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int account_num;
    char last_name[15];
    char first_name[20];
    double money;
}customer;

int main()
{
    FILE* trans, *oldmast, *newmast;

    trans = fopen("14_2trans.txt","r");
    oldmast = fopen("14_2oldmast.txt","r");
    newmast = fopen("newmast.txt","w");

    customer client = {0, "", "", 0};

    int old_num = 0;
    double old_money = 0;

    fscanf(oldmast,"%d %lf", &old_num, &old_money);

    for(;!feof(oldmast);)
    {
        fscanf(trans, "%d %s %s %lf", &client.account_num, client.first_name, client.last_name, &client.money);

        if(client.account_num == old_num){
            client.money += old_money;
            printf("%d %s %s %.2lf\n", client.account_num, client.first_name, client.last_name, client.money);

            fscanf(oldmast,"%d %lf", &old_num, &old_money);
        }
        else printf("Unmatched transaction record for account number...\n");

        fprintf(newmast,"%d %s %s %.2lf\n", client.account_num, client.first_name, client.last_name, client.money);
    }

    fclose(trans);
    fclose(oldmast);
    fclose(newmast);

    return 0;
}