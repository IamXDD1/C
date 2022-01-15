#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int account_num;
    char last_name[15];
    char first_name[20];
    double money;
}customer;

int main()
{
    FILE* trans, *oldmast, *newmast;

    trans = fopen("14_3trans.txt","r");
    oldmast = fopen("14_3oldmast.txt","r");
    newmast = fopen("newmast.txt","w");

    customer client = {0, "", "", 0};
    customer temp = {0, "", "", 0};

    int old_num = 0;
    double old_money = 0;

    fscanf(oldmast,"%d %lf", &old_num, &old_money);
    fscanf(trans, "%d %s %s %lf", &client.account_num, client.first_name, client.last_name, &client.money);

    for(;!feof(trans);){

        temp.account_num = client.account_num;
        strcpy(temp.first_name, client.first_name);
        strcpy(temp.last_name, client.last_name);
        temp.money = client.money;

        for(int count = 0;temp.account_num == client.account_num && !feof(trans); count++)
        {
            _Bool check = 0;
            if(client.account_num > old_num){
                if(feof(oldmast)){
                    printf("Unmatched transaction record for account number...\n");
                    fscanf(trans, "%d %s %s %lf", &client.account_num, client.first_name, client.last_name, &client.money);
                }
                else{
                    fscanf(oldmast,"%d %lf", &old_num, &old_money);
                }
            }
            else if(client.account_num < old_num){
                printf("Unmatched transaction record for account number...\n");
                fscanf(trans, "%d %s %s %lf", &client.account_num, client.first_name, client.last_name, &client.money);
            }
            else{
                client.money += old_money;
                old_money = client.money;
                temp.money = client.money;

                check = 1;

                printf("%d %s %s %.2lf\n", client.account_num, client.first_name, client.last_name, client.money);
                fscanf(trans, "%d %s %s %lf", &client.account_num, client.first_name, client.last_name, &client.money);
            }

            if(count > 1 && check == 0){
                temp.money += client.money;
            }
        }

        fprintf(newmast,"%d %s %s %.2lf\n", temp.account_num, temp.first_name, temp.last_name, temp.money);
    }

    fclose(trans);
    fclose(oldmast);
    fclose(newmast);

    return 0;
}