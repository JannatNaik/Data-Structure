#include<iostream>
using namespace std;

struct node{
	int data;
	struct node* next;
	node(int t_data){
		data= t_data;
		next= NULL;
	}
};

class linklist{
	public:
		struct node* head= NULL;
		addlink(int data){
			struct node* newn= new node(data);
			if(!head){
				head= newn;
			}
			else{
				struct node* temp= head;
				while(temp->next){
					temp=temp->next;
				}	
				temp->next=newn;
//				temp=newn;
			}
		}
		
		display(){
			struct node* temp=head;
			while(temp){
				cout<<temp->data<<endl;
				temp=temp->next;
			}
			
		}
};
//begin
struct node* insertbeg(struct node*head, int data){
	struct node* newn= new node(data);
	if(head==NULL){
		head=newn;
	}
	else{
		newn->next=head;
		head=newn;
	}
	return head;
	
}
//
int main(){
	linklist l1;
	l1.addlink(10);
	l1.addlink(20);
	l1.addlink(30);
	l1.addlink(40);
	
	l1.display();
	
	l1.head=insertbeg(l1.head,80);
	cout<<"\n\n";
	l1.display();
	return 0;
}
