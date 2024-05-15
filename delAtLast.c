#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};

struct Node* create(struct Node *head, int n) {
    int val;
    struct Node *tmp = NULL;
     
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;
        if(head == NULL) {
            head = newNode;
            tmp = head;
        } else {
            tmp->next = newNode;
            tmp = newNode;
        }
    }
    return head;
}

void traverse(struct Node *ptr) {
    while(ptr != NULL) {
        printf("The elements are: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node * delLast(struct Node * head){
    struct Node *p = head;
    struct Node *q = head->next;
    while(p->next != NULL){
        p=p->next;
        q=q->next;
    }
    p->next = NULL;
    free(q);
    return p;
}

int main() {
    int n;
    struct Node *head = NULL;
    printf("Enter the size of the linked list: ");
    scanf("%d", &n);
    
    printf("Enter the values of the linked list:\n");
    head = create(head, n);
    printf("Original linked list:\n");
    traverse(head);
    
    head = deleteAIAnyndex(head,3); 
    printf("Linked list after insertion at first:\n");
    traverse(head);
    
    return 0;
}
