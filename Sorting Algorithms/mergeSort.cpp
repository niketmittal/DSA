#include <bits/stdc++.h>
using namespace std;

int merge(int arr[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}   

int mergesort(int arr[], int l, int r){
    if(l>=r)
        return 0;

    int m =l+ (r-l)/2;
    mergesort(arr,l,m);
    mergesort(arr,m+1,r);
    merge(arr,l,m,r);
}

void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}

int main(){
    int arr[] = { 44, 6, 8, 111, 7, 6, 7, 7, 1, 6, 44, 99999, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<"Given Array :\n";
    printArray(arr, n);

    mergesort(arr, 0, n-1);

    cout<<"\nSorted Array :\n";
    printArray(arr, n);

}
