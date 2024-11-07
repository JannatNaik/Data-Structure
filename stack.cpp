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
class Stack{
	struct node *top;
	public:
		Stack(){
			top=NULL;
		}
	Push(int t_data){
		struct node *newnode = new node(t_data);
		
		if(top==NULL){
			top=newnode;
		}
		else{
//			struct node *curr=top;
			newnode->next=top;
			top=newnode;
		}
	}
	Pop(){
		if(top==NULL)
		{
			cout<<"Stack is emty..."<<endl;
		}
		else
		{
			struct node *curr=top;
			top=curr->next;
			delete(curr);
			cout<<"Pop operation Done..."<<endl;
		}
	}
	show()
	{
		struct node *curr=top;
		while(curr!=NULL)
		{
			cout<<"Data:"<<curr->data<<endl;
			curr=curr->next;
		}
		
	}
};
main()
{
	Stack s1;
	s1.Pop();
	s1.Push(10);
	s1.Push(20);
	s1.Push(30);
	s1.show();
	s1.Pop();
	s1.show();
	
}
