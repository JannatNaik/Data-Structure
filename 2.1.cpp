//1.  Insert an element at the beginning, middle ,end  in doubly circular
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

// insertion at the end of the linked list
struct node * insert_end(struct node * head, int info){
	struct node * newn = new node(info);
	
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

//insertion at the beginning of the linkedlist
struct node * insert_beg(struct node * head, int info){
	struct node * newn = new node(info);
	
	if(head == NULL){
		head = newn;
		newn->next = head;
		newn->prev = head;
	}else{
		newn->next = head;
		newn->prev = head->prev;
		head->prev->next = newn;
		head->prev = newn;
		head = newn;
	}
}

//insertion after a given node
struct node * insert_mid(struct node * head, int key, int info){
 	struct node * newn = new node(info);
 	
	 if(head == NULL){
 		head = newn;
		newn->next = head;
		newn->prev = head;
	 }else{
	 	struct node * temp = head;
	 	while(temp->data != key){
	 		temp = temp->next;
		}
		newn->data = info;
		newn-> prev = temp;
		newn->next = temp->next;
		temp->next->prev = newn; 
        temp->next = newn;
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
	
	l1.show();
	
	//insertion function call
	l1.head = insert_end(l1.head, 70);
	
	cout<<"\nlinkelist after insertion at the end."<<endl;
	l1.show();
	
	//insertion function call
	l1.head = insert_beg(l1.head, 20);
	
	cout<<"\nlinkedlist after insertion at the beginning."<<endl;
	l1.show();
	
	//insertion function call
	l1.head = insert_mid(l1.head, 40, 41);
	
	cout<<"\nlinklist after insertion after a given node."<<endl;
	l1.show();
		
	return 0;
}

