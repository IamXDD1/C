#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node* next;
    int val;
}Node;

void insert(Node** head, int val);
void displayList(Node* head);
void printListBackward(Node* head);

int main()
{
    Node* head = NULL;

    for(int i=0; i<10; i++){
        int tmp = 0;
        scanf("%d", &tmp);
        insert(&head, tmp);
    }

    displayList(head);
    printListBackward(head);

    return 0;
}

void insert(Node** head, int val){
    Node* newNode = malloc(sizeof(Node));

    newNode->next = NULL;
    newNode->val = val;

    Node* curr = *head;
    Node* pre = NULL;

    while(curr!=NULL && curr->val < val){
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
void displayList(Node* head){
    for(;head != NULL; head = head->next){
        printf("%4d", head->val);
    }
    printf("\n");
}
void printListBackward(Node* head){
    if(head != NULL){
        printListBackward(head->next);
        printf("%4d", head->val);
    }
}