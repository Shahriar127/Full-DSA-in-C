#include<stdio.h>


int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    printf("Desired value: ");
    int val; scanf("%d",&val);
    int l = 0; int r = n -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if(a[mid] == val){
            printf("Found");
            return 0;
        }
        else if(a[mid] < val) l = mid + 1;
        else r = mid - 1;   
    }
    printf("Not Found");

    return 0;
}