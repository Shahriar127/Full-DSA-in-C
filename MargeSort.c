#include<stdio.h>
#define N 100000
int a[N];

void merge(int l, int r, int mid){
    int l_sz = mid - l + 1;
    int L[l_sz + 1];
    int r_sz = r - mid;
    int R[r_sz + 1]; 
    for(int i = 0; i < l_sz; i++){
        L[i] = a[i + l];
    }
    for(int i = 0; i < r_sz; i++){
        R[i] = a[i + mid + 1];
    }
    L[l_sz] = R[r_sz] = __INT_MAX__;

    int l_i = 0;
    int r_i = 0;
    for(int i = l; i <= r; i++){
        if(L[l_i] <= R[r_i]){
            a[i] = L[l_i];
            l_i++;
        }
        else{
            a[i] = R[r_i]; 
            r_i++;
        }
    }
}

void mergeSort(int l, int r){
    if(l == r) return;
     int mid = (l + r) / 2;
     mergeSort(l, mid);
     mergeSort(mid + 1, r);
     merge(l, r, mid); 
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    mergeSort(0, n - 1); 
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
