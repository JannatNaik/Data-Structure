//2. Delete an element from the beginning, middle, end in doubly circular
#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
	int data;
	struct node * next;
	struct node * prev;
	node(int t_data){
		data = t_data;
		next = NULL;
		prev = NULL;
	}
};

class doubly{
	public:
		struct node * head;
		doubly(){
			head = NULL;
		}
		
		void add_node(int data){
			struct node * newn = new node(data);
			
			if(head == NULL){
				head = newn;
				newn->next = head;
				newn->prev = head;
			}else{
				struct node * temp = head->prev;
				temp->next = newn;
				newn->prev = temp;
				newn->next = head;
				head->prev = newn;
			}	
		}
		
		void show(){
			if(head == NULL){
				cout << "list is empty!!" << endl;
				return;
			}
			
			struct node * temp = head;
			do{
				cout << temp->data << endl;
				temp = temp->next;
			}while(temp != head);
			cout << endl;
		}
};
 
//function for deletion from the beginning of the linked list
struct node * delbeg(struct node * head){
	if(head == NULL){
		cout<<"list is empty!!"<<endl;
	}else{
		struct node *curr;
		curr = head;
		if(head->next == head){
			free(curr);
		}else{
			head = head->next;
			head->prev = curr->prev;
			curr->prev->next = head;
			free(curr);
		}
	}
	return head;
}

//deletion from the end of the linked list
struct node * delend(struct node * head){
	if(head == NULL){
		cout<< "list is empty!!"<<endl;
	}else{
		struct node *curr, *pre;
		curr = head;
		pre = curr;
		while(curr->next != head){
			pre = curr;
			curr = curr->next;
		}
		if(curr == head){
			head = NULL;
		}else{
			pre->next = head;
			head->prev = pre;
		}
		free(curr);
	}
	return head;
}

//deletion after a given node 
struct node * delmid(struct node * head, int key){
	if(head == NULL){
		cout<<"list is empty!!"<<endl;
	}else{
		struct node *curr, *pre;
		curr = head;
		pre = curr;
		do{
			pre = curr;
			curr = curr->next;
		}
		while(curr != NULL && curr->data != key);
		
		if(curr == head){
			cout<<"key is not found!!"<<endl;
			return head;
		}
		pre->next = curr->next;
		curr->next->prev = pre;
			
		if(curr == head){
			head = head->next;
		}
		free(curr);
	}
	return head;
}

int main(){
	doubly l1;
	l1.add_node(23);
	l1.add_node(35);
	l1.add_node(40);
	l1.add_node(45);
	l1.add_node(50);
	l1.add_node(58);
	l1.add_node(60);
	
	cout<<"\nlinklist before deletion "<<endl;
	l1.show();
	
	//deletion function call
	l1.head = delbeg(l1.head);
	
	cout<<"\nlinklist after deletion from the beginning"<<endl;
	l1.show();
	
	//deletion function call
	l1.head = delend(l1.head);
	
	cout<<"\nlinklist after deletion from the end"<<endl;
	l1.show();
	
	//deletion function call
	l1.head = delmid(l1.head, 45);
	
	cout<<"\nlinklist after deletion after a given node"<<endl;
	l1.show();
	
	return 0;
}
