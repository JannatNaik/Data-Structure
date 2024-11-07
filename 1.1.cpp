//1.1 Insert an element at the beginning, middle ,end
#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
	int data;
	struct node * next;
	node(int t_data){
		data = t_data;
		next = NULL;
	}
};

class linklist{
	public:
		struct node * head;
		add_link(int t_data){
			struct node *newnode = new node(t_data);
			if(!head){
				head = newnode;
			}
			else{
				struct node * current = head;
				while(current->next){
					current = current->next;
				}
				current->next = newnode;
			}
		}
		
		show(){
			struct node * current = head;
			while(current){
				cout << current->data<<endl;
				current = current->next;
			}
		}
};

//insertion of node at the beginning of the linkedlist
struct node * insert_beginning(struct node *& head, int info){
	struct node * newn;
	newn = (struct node*)malloc(sizeof(struct node));
	newn->data = info;
	newn->next = head;
	head = newn;
	return head; 
}

//insertion of a node at the end of the linkedlist
struct node * insert_end(struct node * head, int info){
	struct node *ptr, *newn;
	newn = (struct node*)malloc(sizeof(struct node));
	newn->data = info;
	newn->next = NULL;
	ptr = head;
	if(ptr != NULL){
		while(ptr->next != NULL){
			ptr = ptr->next;
		}
		ptr->next = newn;
	}
	else{
		head = newn;	
	}
	return head;
}

//insertion of a node at the middle of the linkedlist
struct node * insert_mid(struct node * head, int x, int info){
	struct node *ptr, *newn;
	newn = (struct node*)malloc(sizeof(struct node));
	newn->data = info;
	ptr = head;
	while(ptr->data != x && ptr != NULL){
		ptr = ptr->next;
	}
	if(ptr->data == x){
		newn->next = ptr->next;
		ptr->next = newn;
	}
	return head;
}

int main(){
linklist l1;
l1.add_link(21);
l1.add_link(25);
l1.add_link(30);

cout<< "linklist before insertion."<<endl;
l1.show();

//insertion function call
insert_beginning(l1.head, 10);

cout<<"\nlinklist after insertion at beginning."<<endl;
l1.show();

//insertion function call
insert_end(l1.head, 90);

cout<<"\nlinklist after insertion at end."<<endl;
l1.show();

//insertion function call
 insert_mid(l1.head, 25, 100);
 
 cout<< "\nlinklist after insertion at the middle."<<endl;
 l1.show();
 
return 0;	
}

