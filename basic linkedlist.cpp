#include<iostream>
using namespace std;
struct node{
	int data;
	struct node* next;
	node(int t_data)
	{
		data=t_data;
		next=NULL;
	}
};
class linklist{
	struct node *head;
	public:
		add_link(int t_data)
		{
			struct node *newnode = new node(t_data);
			if(!head)
			{
				head=newnode;
			}
			else
			{
				struct node * current = head;
				while(current->next){
					current=current->next;
				}
				
				current->next=newnode;
			}
		}
		show()
		{
			struct node * current = head;
			while(current)
			{
				cout<<current->data<<endl;
				current=current->next;
			}
		}
};


main()
{
//	struct node * head = new node(20);
//	struct node * one = new node(10);
//	head->next=one;
//	struct node * current = head;
//	while(current)
//	{
//		cout<<current->data<<endl;
//		current=current->next;
//	}
linklist l1;
l1.add_link(21);
l1.add_link(25);
l1.add_link(30);
l1.show();
	
}
