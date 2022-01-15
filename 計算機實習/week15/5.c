#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node* next;
    char val;
}Node;

void insert(Node** head, char val);
void printListBackward(Node* head);

int main()
{
    Node* head = NULL;

    char input[200];

    gets(input);

    for(int i=0; input[i] != '\0'; i++){
        insert(&head, input[i]);
    }

    printListBackward(head);

    return 0;
}

void insert(Node** head, char val){
    Node* newNode = malloc(sizeof(Node));

    newNode->next = NULL;
    newNode->val = val;

    Node* curr = *head;
    Node* pre = NULL;

    while(curr!=NULL){
        pre = curr;
        curr = curr->next;
    }

    if(pre == NULL){
        newNode->next = *head;
        *head = newNode;
    }
    else{
        pre->next = newNode;
        newNode->next = curr;
    }


    return;
}

void printListBackward(Node* head){
    if(head != NULL){
        printListBackward(head->next);
        printf("%c", head->val);
    }
}