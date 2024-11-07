//bubble sort

#include<iostream>
using namespace std;

//function for swapping
void swap(int *arr, int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void bubblesort(int arr[], int n){
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			if(arr[j]>arr[j+1]){
				swap(arr, j, j+1);
			}
		}
	}
	
	cout<<"sorted array:"<<endl;
	for(int i=0; i<n; i++){
		cout<<arr[i]<<endl;
	}
}

int main(){
	int arr[] = {20, 99, 49, 88, 100, 3};
	int n = sizeof(arr)/sizeof(arr[0]);
	bubblesort(arr, n);
	
	return 0 ;
}
