#include<bits/stdc++.h>
using namespace std;

int getMax(int arr[], int n) 
{ 
	int mx = arr[0]; 
	for (int i = 1; i < n; i++) 
		if (arr[i] > mx) 
			mx = arr[i]; 
	return mx; 
} 

void countSort(int arr[], int n, int exp) 
{ 
	int output[n];
	int i, count[10] = { 0 }; 

	for (i = 0; i < n; i++) 
		count[(arr[i] / exp) % 10]++; 

	for (i = 1; i < 10; i++) 
		count[i] += count[i - 1]; 

	for (i = n - 1; i >= 0; i--) { 
		output[count[(arr[i] / exp) % 10] - 1] = arr[i]; 
		count[(arr[i] / exp) % 10]--; 
	} 

	for (i = 0; i < n; i++) 
		arr[i] = output[i]; 
} 

void radixsort(int arr[], int n) 
{ 
	int m = getMax(arr, n); 

	for (int exp = 1; m / exp > 0; exp *= 10) 
		countSort(arr, n, exp); 
} 

void print(int arr[], int n) 
{ 
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 
} 

int main() 
{ 
	int arr[] = { 44, 6, 8, 111, 7, 6, 7, 7, 1, 6, 44, 99999, 0 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	
	radixsort(arr, n); 
	print(arr, n); 
	return 0; 
}
