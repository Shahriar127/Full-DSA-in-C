#include<stdio.h>
#include<stdlib.h>
struct stack{
    int * arr;
    int top;
    int size;
};

int isEmpty(struct stack *ptr){
    if(ptr->top == -1) return 1;
    else return -1;
}

int isFull(struct stack *ptr){
    if(ptr->top == ptr->size -1){
        return 1;
    }
    else return -1;
}
void push(struct stack *ptr, int val){
    if(!isFull(ptr)){
        printf("Stack is full.");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
int main(){
   struct stack *sp = (struct stack *) malloc (sizeof(struct stack));
   sp->size = 10;
   sp->top = -1;
   sp->arr = (int *)malloc(sp->size *sizeof(int));
   printf("Before pushing, Full: %d\n", isFull(sp));
   printf("Before pushing, Empty: %d\n", isEmpty(sp));
   printf("Enter into stack.");
   for(int i =0; i < sp->size; i++){
       int a; 
       scanf("%d",&a);
       push(sp,a);
   }
    printf("Output the stack :");
     for(int i = 0; i < sp->top ; i++) {
        printf("%d ", sp->arr[i]);
    }

}