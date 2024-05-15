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
    for(int i = 0;i < n; i++){
        if(a[i] == val)  {
            printf("Found");
            return 0;
        }
    }
    printf("Not Found");

    return 0;
}