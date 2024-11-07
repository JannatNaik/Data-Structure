// circular queue using linklist

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
		struct node *front, *rear;
		queue(){
			front = rear = NULL;
		}
		
		void enqueue(int data){
			struct node* newn = new node(data);
			if(front == NULL){
				front = newn;
				newn->next = front;
			}else{
				struct node* curr = front;
				while(curr->next != front){
					curr = curr->next;
				}
				rear = newn;
				curr->next = newn;
				newn->next = front;
			}
		}
		
		void dequeue(){
			struct node* curr = front;
			struct node* curr2 = rear;
			front = curr->next;
			curr2->next = curr->next;
			delete(curr);
		}
		
		void show(){
			struct node* curr = front;
			do{
				cout<<curr->data<<" ";
				curr = curr->next;
			}while(curr != front);
			
		}
};

int main(){
	queue q1;
	q1.enqueue(10);
	q1.enqueue(20);
	q1.enqueue(30);
	q1.enqueue(40);
	q1.enqueue(50);
	
	cout<<"\n";
	q1.show();
	
	cout<<"\n";
	q1.dequeue();
	q1.dequeue();
	
	q1.show();
	
	return 0;
}
