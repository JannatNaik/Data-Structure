#include<iostream>
using namespace std;
struct node{
	int data;
	struct node *next;
	node(int t_data)
	{
		data=t_data;
		next=NULL;
	}
};
class Queue{
	struct node* rear;
	struct node* front;
	public:
		Queue(){
			rear=NULL;
			front=NULL;
		}
	enqueue(int t_data){
		struct node *newnode = new node(t_data);
		if(front==NULL)
		{
			front=newnode;
			rear=newnode;
//			front->next=rear;
		}
		else
		{
			struct node* curr = front;
			while(curr->next!=NULL)
			{
				curr=curr->next;
			}
			rear=newnode;
			curr->next=rear;
		}
	}
	dequeue(){
		struct node* curr = front;
		front=curr->next;
		delete(curr);
		
	}
	show()
	{
		struct node* curr = front;
		while(curr!=NULL)
		{
			cout<<"Data:"<<curr->data<<endl;
			curr=curr->next;
		}
		cout<<endl;
		cout<<"Your front is :"<<front->data<<endl;
		cout<<"Your Rear is :"<<rear->data<<endl;
	}
	
	
};
main()
{
	Queue q1;
	q1.enqueue(20);
	q1.enqueue(30);
	q1.enqueue(40);
	q1.show();
	q1.dequeue();	
	q1.show();
}
