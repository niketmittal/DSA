#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high){
    int pivot = arr[low];
    int j = low;

    for (int i = low+1; i <= high; i++){
        if (arr[i] < pivot){
            j++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[j], &arr[low]);
    return j;
}

int rand_partition(int arr[], int low, int high){

    // to prevent sequence repetition between runs
    srand(time(NULL));
    int random = low + rand()%(high-low); //generates number b/w high and low included
    //cout<<random<<endl;
    swap(&arr[low], &arr[random]);

    return partition(arr, low, high);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high){
        int m = rand_partition(arr, low, high);

        quickSort(arr, low, m - 1);
        quickSort(arr, m + 1, high);
    }
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

    quickSort(arr, 0, n-1);

    cout<<"\nSorted Array :\n";
    printArray(arr, n);

}
