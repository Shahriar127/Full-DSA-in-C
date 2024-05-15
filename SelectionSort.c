#include<stdio.h>
int main(){
    int n; 
    scanf("%d",&n);
    int a[n];
    for(int i = 0;i < n; i++){
        scanf("%d",&a[i]);
    }
    int i = 0;
    for( i = 0; i< n -1;i++){
        int mx = i;
        for(int j = i + 1; j < n; j++){
            if(a[mx] > a[j]) {
                mx = j;
            }
        }
        if(mx != i) {
            int tmp = a[mx];
            a[mx] = a[i];
            a[i] = tmp;
        }

    }
    for(int i = 0;i < n; i++){
        printf("%d ",a[i]);
    }
}