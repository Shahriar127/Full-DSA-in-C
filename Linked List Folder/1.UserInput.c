#include<stdio.h>

struct Node 
{
    int data;
    struct Node *next;
};

void create(struct Node *head, int n){
    int val;
    struct Node *tmp = NULL;
     
    
    for(int i = 0;i < n; i++){
        scanf("%d",&val);
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;
        if(head == NULL){
            head = newNode;
            tmp = head;
        }
        else {
            tmp->next = newNode;
            tmp = newNode;
        }
    }
     return head;
}

void traverse(struct Node *ptr){
    while(ptr != NULL){
        printf("The elements are: %d\n", ptr->data);
        ptr = ptr->next;
    }
}


int main(){
    int n;
    struct Node *head = NULL;
    printf("Enter the size of Linklist:");
    scanf("%d",&n);
    
     printf("Enter the values of Linklist:");
     create(head,n);
     traverse(head);
     return 0;
}
