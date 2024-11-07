//basic stack using array

#include<iostream>
using namespace std;

#define MAX 100
class stack{
	public:
		int arr[MAX];
		int top;
		
		stack(){
			top = -1;
		}
		
		bool push(int data){
			if(top >= (MAX-1)){
				cout<<"stack is overflow";
				return false;
			}else{
//				arr[++top] = data; or
				top = top+1;
				arr[top] = data;
				cout<<"\ndata pushed successfully\n";
				return true;
			}
		}
		
		int pop(){
			if(top < 0){
				cout<<"stack is underflow";
				return 0;
			}else{
//				int x = arr[top--]; or
				int x = arr[top];
				top = top-1;
				return x;
			}
		}
		
		int peek(){
			if(top<0){
				cout<<"stack is empty";
				return 0;
			}else{
				int x = arr[top];
				return x;
			}
		}
		
		bool isempty(){
			return (top < 0);
		}
};

int main(){
	stack s1;
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.push(40);
	s1.push(50);
	cout<<s1.peek()<<"is the top element of the stack"<<endl;
	
	int x = s1.pop();
	cout<<x<<"is deleted from the stack"<<endl;
	cout<<s1.peek()<<"is the top element of the stack"<<endl;
	
	cout<<"\nelements present in the list:"<<endl;
	while(!s1.isempty()){
		cout<<s1.peek()<<" ";
		
		s1.pop();
	}
	return 0;
}
