//basic stack using linked list 

#include<iostream>
using namespace std;

struct node{
	int data;
	struct node* next;
	node(int t_data){
		data = t_data;
		next = NULL;
	}
};

class stack{
	public:
		struct node* top;
		stack(){
			top = NULL;
		}
		
		void push(int data){
			struct node* newn = new node(data);
			if(top == NULL){
				top = newn;
			}else{
				newn->next = top;
				top = newn;
			}
		}
		
		int pop(){
			if(top == NULL){
				cout<<"stack is underflow";
				return 0;
			}else{
				struct node* curr = top;
				top = curr->next;
				int x = curr->data;
				delete(curr);
				return x;
			}
		}
		
		int peek(){
			return top->data;
		}
		
		void show(){
			struct node* curr = top;
			while(curr){
				cout<<curr->data<<endl;
				curr  = curr->next;
			}
		}
};

int main(){
	stack s1;
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.push(40);
	s1.push(50);
	
	s1.show();
	
	int x = s1.peek();
	cout<<"\ntop of the stack is:"<<x<<endl;
	
	x = s1.pop();
	cout<<"\n"<<x<<"element is deleted from the stack"<<endl;
	
	x = s1.peek();
	cout<<"\ntop of the stack is:"<<x<<endl;
	
	s1.show();
	
	return 0;
}
