//1.2. Delete an element from the beginning, middle,end
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
		linklist(){
			head = NULL;
		}
		void add_link(int t_data){
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
		
		void show(){
			struct node * current = head;
			while(current){
				cout << current->data<<endl;
				current = current->next;
			}
		}
};

//deletion from the beginning of the linkedlist
struct node * del_beg(struct node * head){
	struct node * ptr;
	if(head == NULL){
		cout << "linklist is empty!" << endl;
	}
	else{
		ptr = head;
		head = head->next;
		free(ptr);
	}
	return head;
}

//deletion from the end of the linkedlist
struct node * del_end(struct node * head){
	struct node *ptr, *prev;
	if(head == NULL){
		cout << "list is empty!"<<endl;
	}else if(head->next == NULL){
		free(head);
	}
	else{
		ptr = head;
		while(ptr->next != NULL){
			prev = ptr;
			ptr = ptr->next;
		}
		prev->next = NULL;
		free(ptr);
	}
	return head;
}

//deletion after a given node in the linkedlist
struct node * del_after(struct node * head, int key){
	struct node *ptr1, *ptr2;
	ptr1 = head;
	while(ptr1->next != NULL){
		if(ptr1->data == key){
			ptr2 = ptr1->next;
			ptr1->next = ptr2->next;
			free(ptr2);
			break;
		}
		ptr1 = ptr1->next;
	}
	return head;
}


int main(){
	linklist l1;
	l1.add_link(21);
	l1.add_link(25);
	l1.add_link(30);
	l1.add_link(35);
	l1.add_link(40);
	l1.add_link(45);
		
	cout<< "linklist before deletion."<<endl;
	l1.show();
	
	//deletion function call
	l1.head = del_beg(l1.head);
	
	cout<<"\nlinklist after deletion from the beginning."<< endl;
	l1.show();
	
	//deletion function call
	l1.head = del_end(l1.head);
	
	cout << "\nlinklist after deletion from the ending."<< endl;
	l1.show();
	
	//deletion function call
	l1.head = del_after(l1.head, 30);
	
	cout << "\nlinklist after deletion after a given node." <<endl;
	l1.show();
	
	return 0;
}
