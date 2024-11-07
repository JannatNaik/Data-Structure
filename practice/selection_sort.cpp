//selection sort

#include<iostream>
using namespace std;

void swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

void selection_sort(int arr[], int n){
	for(int i=0; i<n-1; i++){
		int min_ind = i;
		for(int j = i+1; j<n; j++){
			if(arr[j]<arr[min_ind]){
				min_ind = j;
			}
		}
		
		if(min_ind != i){
			swap(arr[min_ind], arr[i]);
		}
	}
	
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
}

int main(){
	int arr[] = {3, 5, 7, 1, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	selection_sort(arr, n);
	
	return 0;
}
