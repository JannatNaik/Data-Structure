//insertion sort

#include<iostream>
using namespace std;

void insertion_sort(int arr[], int n){
	for(int i=1; i<n; i++){
		int key = arr[i];
		int j = i-1;
		
		while(j>=0 && arr[j]>key){
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = key;
	}
	
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
}


int main(){
	int arr[] = {2, 6, 8, 10, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	insertion_sort(arr, n);
	
	return 0;
}
