//bubble sort

#include<iostream>
using namespace std;

void swap(int *arr, int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void bubble_sort(int arr[], int n){
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			if(arr[j]>arr[j+1]){
				swap(arr, j, j+1);
			}
		}
	}
	
	cout<<"sorted array: "<<endl;
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
}

int main(){
	int arr[] = {3, 5, 7, 8, 2, 9};
	int n = sizeof(arr)/sizeof(arr[0]);
	bubble_sort(arr, n);
	
	return 0;
}
