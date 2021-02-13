#include<bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void siftDown(int arr[], int n, int i){
        int maxindex = i;
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        int l = leftChild;
        if(l < n && arr[l] > arr[maxindex])
                maxindex = l;
        int r = rightChild;
        if(r < n && arr[r] > arr[maxindex])
                maxindex = r;
        if(maxindex != i){
                swap(&arr[i], &arr[maxindex]);
                siftDown(arr, n, maxindex);
        }
}

void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}

void buildHeap(int arr[], int n){ //rearrange array
    for(int i = n/2; i >= 0; i--){
        siftDown(arr, n, i);
    }
}

void heapSort(int arr[], int n){
    buildHeap(arr, n);
    for(int i = n-1; i> 0; i--){
        swap(&arr[0], &arr[i]);
        siftDown(arr, i, 0);
    }
}

int main(){
    int arr[] = { 44, 6, 8, 111, 7, 6, 7, 7, 1, 6, 44, 99999, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<"Given Array :\n";
    printArray(arr, n);

    heapSort(arr, n);

    cout<<"\nSorted Array :\n";
    printArray(arr, n);

    return 0;
}
