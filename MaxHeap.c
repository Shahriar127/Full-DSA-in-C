#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct MaxHeap {
    int size;
    int arr[MAX];
} MaxHeap;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(MaxHeap* heap, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->arr[left] > heap->arr[largest]) {
        largest = left;
    }
    if (right < heap->size && heap->arr[right] > heap->arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(&heap->arr[i], &heap->arr[largest]);
        maxHeapify(heap, largest);
    }
}

void insert(MaxHeap* heap, int key) {
    if (heap->size == MAX) {
        printf("Heap overflow\n");
        return;
    }
    int i = heap->size++;
    heap->arr[i] = key;

    while (i != 0 && heap->arr[(i - 1) / 2] < heap->arr[i]) {
        swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMax(MaxHeap* heap) {
    if (heap->size <= 0) {
        return -1;
    }
    if (heap->size == 1) {
        return heap->arr[--heap->size];
    }
    int root = heap->arr[0];
    heap->arr[0] = heap->arr[--heap->size];
    maxHeapify(heap, 0);
    return root;
}

int main() {
    MaxHeap heap;
    heap.size = 0;

    insert(&heap, 10);
    insert(&heap, 20);
    insert(&heap, 30);

    printf("Max element is %d\n", extractMax(&heap));
    printf("Max element after extraction is %d\n", extractMax(&heap));

    return 0;
}
