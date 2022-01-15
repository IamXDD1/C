#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node* next;
    struct Node* pre;
    int val;
}Node;

void insert(Node** head, int val, int index);
void displayList(Node* head);
void del(Node** head, int val);

int main()
{
    Node* head = NULL;

    for(int tmp = 0;scanf("%d", &tmp);){
        if(tmp == -1) break;

        int val = 0;
        scanf("%d", &val);

        switch(tmp)
        {
            case 1: insert(&head, val, 1); break;
            case 2: insert(&head, val, 2); break;
            case 3: insert(&head, val, 3); break;
            case 4: del(&head, val); break;
        }

        displayList(head);
    }


    return 0;
}

void insert(Node** head, int val, int index){
    Node* newNode = malloc(sizeof(Node));

    newNode->pre = NULL;
    newNode->next = NULL;
    newNode->val = val;

    Node* curr = *head;
    Node* pre = NULL;

    if(index == 1){
        newNode->next = *head;

        if(*head != NULL) (*head)->pre = newNode;

        *head = newNode;
    }
    else if(index == 2){
        while(curr!=NULL){
            pre = curr;
            curr = curr->next;
        }

        if(pre == NULL){
            newNode->next = *head;
            if(*head != NULL) (*head)->pre = newNode;
            *head = newNode;
        }
        else{
            pre->next = newNode;
            newNode->pre = pre;
        }
    }
    else if(index == 3){
        int tmp = 0;
        scanf("%d", &tmp);

        newNode->val = tmp;

        while(curr->val!=val){
            pre = curr;
            curr = curr->next;
        }

        if(pre == NULL){
            newNode->next = *head;
            (*head)->pre = newNode;
            *head = newNode;
        }
        else{
            pre->next = newNode;
            newNode->pre = pre;
            newNode->next = curr;
            curr->pre = newNode;
        }
    }
    return;
}
void displayList(Node* head){
    for(;head != NULL; head = head->next){
        printf("%4d", head->val);
    }
    printf("\n");
}
void del(Node** head, int val){
    Node* curr = *head;
    Node* pre = NULL;

    while(curr!=NULL && curr->val != val){
        pre = curr;
        curr = curr->next;
    }

    if(pre == NULL){
        Node* tmp = *head;
        (*head)->next->pre = NULL;
        *head = (*head)->next;
        free(tmp);
        return;
    }
    else if(curr != NULL){
        Node* tmp = curr;
        pre->next = curr->next;
        if(curr->next != NULL) curr->next->pre = pre;

        free(tmp);
    }
}