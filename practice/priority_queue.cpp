//priority queue

#include<iostream>
using namespace std;

struct node{
	int data;
	int pr;
	struct node* next;
	node(int d, int p){
		data = d;
		pr = p;
		next = NULL;
	}
};

class queue{
	public:
		struct node *front, *rear;
		
		queue(){
			front = rear = NULL;
		}
		
		void enqueue(int data, int priority){
			struct node* newn = new node(data, priority);
			if(front == NULL){
				front = newn;
			}
			else{
				struct node* curr = front;
				if(front->pr > newn->pr){
					newn->next = front;
					front = newn;
				}else{
					while(curr->next != NULL && curr->next->pr < newn->pr){
						curr = curr->next;
					}
					newn->next = curr->next;
					curr->next = newn;
				}
			}
		}
		
		void dequeue(){
			struct node* curr = front;
			front = curr->next;
			delete(curr);
		}
		
		int peek(){
			return front->data;
		}
		
		bool isempty(){
			return (front == NULL);
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
	q1.enqueue(40, 4);
	q1.enqueue(10, 1);
	q1.enqueue(20, 2);
	q1.enqueue(30, 3);
	
	q1.show();
	
	cout<<endl;
	q1.dequeue();
	
	q1.show();
	
}
