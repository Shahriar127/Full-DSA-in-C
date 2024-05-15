#include<bits/stdc++.h>
using namespace std;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int partition(int a[],int low,int high){
    int i,j;
    int p = a[high - 1];
    for(i = low -1,j = low;j <high; j++){
        if(a[j] < p){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[high],a[i + 1]);
    return i + 1;
}

void quickSort(int a[],int low,int high){
     if(low >= high) return;
     int p = partition(a,low,high);
     quickSort(a,low,p-1);
     quickSort(a,p+1,high);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int a[n];

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) cin >> a[i];

    quickSort(a, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    return 0;
}

