//queue implementation using linklist

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

class queue{
	public:
		struct node* front;
		struct node* rear;
		
		queue(){
			front = rear = NULL;
		}	
		
		void enqueue(int data){
			struct node* newn = new node(data);
			if(front == NULL){
				front = rear = newn;
			}
			else{
				struct node* curr = front;
				while(curr->next != NULL){
					curr = curr->next;
				}
				rear = newn;
				curr->next = newn;
			}
		}
		
		void dequeue(){
			struct node* curr = front;
			front = curr->next;
			delete(curr);
		}
		
		void show(){
			struct node* curr = front;
			while(curr){
				cout<<curr->data<<" ";
				curr = curr->next;
			}
		}
};

int main(){
	queue q1;
	q1.enqueue(10);
	q1.enqueue(20);
	q1.enqueue(30);
	q1.enqueue(40);
	q1.enqueue(50);
	
	q1.show();
	cout<<endl;
	q1.dequeue();
	cout<<endl;
	q1.show();
	
	return 0;
}
