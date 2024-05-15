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

void search(struct Node * ptr,int val){
       while(ptr != NULL){
        if(ptr->data == val) {
            printf("Found Data.\n");
            return 0;
        }
       }
       printf("Not Found.\n");
}
void traverse(struct Node *ptr) {
    while(ptr != NULL) {
        printf("The elements are: %d\n", ptr->data);
        ptr = ptr->next;
    }
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
    
     search(head,3); 
    printf("Linked list after insertion at first:\n");
    traverse(head);
    
    return 0;
}
