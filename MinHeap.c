#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

// Structure to represent a min heap
struct MinHeap {
    int *array;
    int size;
    int capacity;
};

// Function to create a new min heap
struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->capacity = capacity;
    minHeap->size = 0;
    minHeap->array = (int*)malloc(capacity * sizeof(int));
    return minHeap;
}

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted with node i
void minHeapify(struct MinHeap* minHeap, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < minHeap->size && minHeap->array[left] < minHeap->array[smallest])
        smallest = left;
    
    if (right < minHeap->size && minHeap->array[right] < minHeap->array[smallest])
        smallest = right;
    
    if (smallest != i) {
        swap(&minHeap->array[i], &minHeap->array[smallest]);
        minHeapify(minHeap, smallest);
    }
}

// Function to insert a new element into the min heap
void insert(struct MinHeap* minHeap, int value) {
    if (minHeap->size == minHeap->capacity) {
        printf("Overflow: Could not insert element into heap.\n");
        return;
    }

    // Insert the new element at the end
    int i = minHeap->size;
    minHeap->array[i] = value;
    minHeap->size++;

    // Fix the min heap property if it is violated
    while (i != 0 && minHeap->array[(i - 1) / 2] > minHeap->array[i]) {
        swap(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to extract the minimum element from the min heap
int extractMin(struct MinHeap* minHeap) {
    if (minHeap->size <= 0)
        return -1; // If heap is empty

    if (minHeap->size == 1) {
        minHeap->size--;
        return minHeap->array[0];
    }

    // Store the minimum value and remove it from the heap
    int root = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;

    // Fix the min heap property
    minHeapify(minHeap, 0);

    return root;
}

// Function to print the elements of the min heap
void printMinHeap(struct MinHeap* minHeap) {
    printf("Min Heap elements: ");
    for (int i = 0; i < minHeap->size; ++i)
        printf("%d ", minHeap->array[i]);
    printf("\n");
}

int main() {
    // Create a min heap
    struct MinHeap* minHeap = createMinHeap(MAX_HEAP_SIZE);

    // Insert elements into the min heap
    insert(minHeap, 3);
    insert(minHeap, 2);
    insert(minHeap, 1);
    insert(minHeap, 15);
    insert(minHeap, 5);
    insert(minHeap, 4);
    insert(minHeap, 45);

    // Print the elements of the min heap
    printMinHeap(minHeap);

    // Extract the minimum element
    printf("Extracted minimum element: %d\n", extractMin(minHeap));

    // Print the elements of the min heap after extraction
    printMinHeap(minHeap);

    return 0;
}
