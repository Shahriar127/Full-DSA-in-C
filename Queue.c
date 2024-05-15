#include<stdio.h>
#include<stdlib.h>

struct queue{
    int * arr;
    int front;
    int rear;
    int size;
};

int isEmpty(struct queue *ptr){
    if(ptr->front == -1 || ptr->front > ptr->rear) return 1;
    else return 0;
}

int isFull(struct queue *ptr){
    if(ptr->rear == ptr->size - 1) return 1;
    else return 0;
}

void enqueue(struct queue *ptr, int val){
    if(isFull(ptr)){
        printf("Queue is full.\n");
    }
    else{
        if(ptr->front == -1)
            ptr->front = 0;
        ptr->rear++;
        ptr->arr[ptr->rear] = val;
    }
}

int dequeue(struct queue *ptr){
    if(isEmpty(ptr)){
        printf("Queue is empty.\n");
        return -1; 
    }
    else{
        int val = ptr->arr[ptr->front];
        ptr->front++;
        return val;
    }
}

int main(){
    struct queue *q = (struct queue *) malloc (sizeof(struct queue));
    q->size = 10;
    q->front = -1;
    q->rear = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));
    
    printf("Before enqueuing, Full: %d\n", isFull(q));
    printf("Before enqueuing, Empty: %d\n", isEmpty(q));
    
    for(int i = 0; i < 8; i++) {
        enqueue(q, i * 2);
    }
    
    printf("After enqueuing, Full: %d\n", isFull(q));
    printf("After enqueuing, Empty: %d\n", isEmpty(q));
    
    printf("Dequeuing elements: ");
    while (!isEmpty(q)) {
        printf("%d ", dequeue(q));
    }
    printf("\n");

    
    free(q->arr);
    free(q);
    
    return 0;
}
