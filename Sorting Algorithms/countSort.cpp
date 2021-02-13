#include<bits/stdc++.h>
using namespace std;
#define m 5

void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}

void countSort(int arr[], int n){
    int output[n];
    int count[m];
    memset(count, 0, sizeof(count));

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    int pos[m];
    memset(pos, 0, sizeof(pos));
    pos[0] = 1;
    for (int i = 1; i < m; i++)
    {
        pos[i] = pos[i-1] + count[i-1];
    }

    for (int i = 0; i < n; i++)
    {
        output[pos[arr[i]]-1] = arr[i];
        pos[arr[i]]++;
    }

    cout<<endl;
    cout<<"\nSorted Array :\n";
    for (int i = 0; i < n; i++)
        cout << output[i] << " ";

}

int main(){
    int arr[] = { 0,0,3,3,1,0,0,1,0,2,2,0,1,3,2 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<"Given Array :\n";
    printArray(arr, n);

    countSort(arr, n);


    //printArray(arr, n);

    return 0;
}
