//queue using array

#include<iostream>
using namespace std;
#define max 100

class queue{
	public:
		int q[max];
		int front, rear;
		queue(){
			front = rear = -1;
		}
		
		void enqueue(int data){
			if(rear == max-1){
				cout<<"queue is overflow";
			}else{
				if(rear == -1){
					front = rear = 0;
					q[rear] = data;
				}else{
					rear++;
					q[rear] = data;
				}
			}
		}
		
		int dequeue(){
			int x;
			if(front == -1){
				cout<<"queue is underflow";
			}else{
				x = q[front];
				if(front == rear){
					front = rear = -1;
				}else{
					front++;
				}
				return x;
			}
		}
		
		bool isfull(){
			return (rear == max-1);
		}
		
		bool isempty(){
			return (front == -1);
		}
		
		void show(){
			while(!isempty()){
				cout<<q[front]<<" ";
		
				dequeue();
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
	
	q1.isfull();
	q1.isempty();
	
	cout<<q1.dequeue()<<" element deleted from the list"<<endl;
	
	q1.show();
	
	return 0;
	
}
