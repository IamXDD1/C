#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node* next;
    struct Node* pre;
    char val;
}Node;

void insert(Node** head, Node** end, char val);

int palindromes(Node* head, Node* end){
    if(head == NULL || head->next == end->pre || head->pre == end) return 1;
    else
    {
        if(head->val != end->val) return 0;
        return palindromes(head->next, end->pre);
    }
}

int main()
{
    Node* head = NULL;
    Node* end = NULL;

    char input[200];
    gets(input);

    for(int i=0; input[i] != '\0'; i++)
    {
        if((input[i] <= 'z' && input[i] >= 'a') || (input[i] <= 'Z' && input[i] >= 'A')){
            insert(&head, &end, tolower(input[i]));
        }
    }

    if(palindromes(head, end)) printf("True");
    else printf("False");

    return 0;
}

void insert(Node** head, Node** end, char val){
    Node* newNode = malloc(sizeof(Node));

    *end = newNode;
    newNode->pre = NULL;
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
        if(*head != NULL) (*head)->pre = newNode;
        *head = newNode;
    }
    else{
        pre->next = newNode;
        newNode->pre = pre;
    }

    return;
}