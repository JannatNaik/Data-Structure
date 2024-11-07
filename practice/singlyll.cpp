//singly linked list creation, insertion (beginning, middle, end), deletion (beginning, middle, end), traversal, updation, reversal

#include<iostream>
using namespace std;

struct node{
	int data;
	struct node* next;
	node(int t_data){
		data = t_data;
		next = NULL;
	}
};

class linklist{
	public:
		struct node *head;
		linklist(){
			head = NULL;
		}
		
		void add_link(int data){
			struct node* newn = new node(data);
			if(head == NULL){
				head = newn;
			}else{
				struct node* curr = head;
				while(curr->next){
					curr = curr->next;
				}
				curr->next = newn;
			}
		}
		
		void show(struct node* head){
			struct node* curr = head;
			while(curr){
				cout<<curr->data<<" ";
				curr = curr->next;
			}
		}
};

//function for insertion at the beginning 
struct node* addbeg(struct node *head, int data){
	struct node* newn = new node(data);
	if(head == NULL){
		head = newn;
	}else{
		newn->next = head;
		head = newn;
	}
	
	return head;
}

//function for insertion at the middle of the list
struct node* addmid(struct node *head, int data, int key){
	struct node *newn = new node(data);
	if(head == NULL){
		head = newn;
	}else{
		struct node *curr = head;
		while(curr->data != key && curr->next != NULL){
			curr = curr->next;
		}
		if(curr->data == key){
				newn->next = curr->next;
				curr->next = newn;
		}
	}
	return head;
}

//function to add node at the end of the linklist
struct node* addend(struct node* head, int data){
	struct node * newn = new node(data);
	if(head == NULL){
		head = newn;
	}else{
		struct node *curr = head;
		while(curr->next != NULL){
			curr = curr->next;
		}
		curr->next = newn;
	}
	
	return head;
}

//function to delete node from the beginning
struct node* delbeg(struct node* head){
	struct node* curr = head;
	if(head == NULL){
		cout<<"list is already empty!!";
	}else{
		head = curr->next;
		delete(curr);
	}
	return head;
}

//function to delete node from middle
struct node* delmid(struct node* head, int key){
	struct node *curr, *ptr;
	ptr = head;
	if(head == NULL){
		cout<<"list is already empty";
	}else{
		while(ptr->next != NULL){
			ptr = ptr->next;
			if(ptr->data == key){
				curr = ptr->next;
				ptr->next = curr->next;
				delete(curr);
			}
		}
	}
	return head;
}

//function to delete an element from the end of the list
struct node *delend(struct node*head){
	if(head == NULL){
		cout<<"list is already empty!!";
	}else{
		struct node *curr, *prev;
		curr = head;
		while(curr->next != NULL){
			prev = curr;
			curr = curr->next;
		}
		prev->next = NULL;
		delete(curr);
	}
	return head;
}

//function to update an element from the list
struct node *updatenode(struct node *head, int ndata, int key){
	struct node *curr, *prev;
	curr = head;
	if(head == NULL){
		cout<<"list is already empty!!";
	}else{
		while(curr->next != NULL){
			curr = curr->next;
			if(curr->data == key){
				curr->data = ndata;
			}
		}
	}
	return head;
}

//function to reverse the linklist
struct node* reverse(struct node* head){
	struct node* prev = NULL;
    struct node* curr = head;
    struct node* next = NULL;
    
    while (curr != NULL) {
        next = curr->next; // Store next node
        curr->next = prev; // Reverse current node's pointer
        prev = curr;       // Move pointers one position ahead
        curr = next;
    }
    head = prev;
    return head;
}

int main(){
	linklist l1;
	l1.add_link(10);
	l1.add_link(20);
	l1.add_link(30);
	l1.add_link(40);
	l1.add_link(50);
	
	cout<<"before linklist: "<<endl;
	l1.show(l1.head);
	
	cout<<"\n";
	
	cout<<"\nafter insertion at beginning: "<<endl;
	l1.head = addbeg(l1.head, 5);
	l1.show(l1.head);
	
	cout<<"\n";
	
	cout<<"\nafter insertion at middle: "<<endl;
	l1.head = addmid(l1.head, 25, 20);
	l1.show(l1.head);
	
	cout<<"\n";
	
	cout<<"\nafter insertion at end: "<<endl;
	l1.head = addend(l1.head, 55);
	l1.show(l1.head);
	
	cout<<"\n";
	
	cout<<"\nafter deletion at beginning: "<<endl;
	l1.head = delbeg(l1.head);
	l1.show(l1.head);
	
	cout<<"\n";
	
	cout<<"\nafter deletion at middle: "<<endl;
	l1.head = delmid(l1.head, 20);
	l1.show(l1.head);
	
	cout<<"\n";
	
	cout<<"\nafter deletion at end: "<<endl;
	l1.head = delend(l1.head);
	l1.show(l1.head);
	
	cout<<"\n";
	
	cout<<"\nafter updation: "<<endl;
	l1.head = updatenode(l1.head, 22, 30);
	l1.show(l1.head);
	
	cout<<"\n";
	
	cout<<"\nafter reversal: "<<endl;
	l1.head = reverse(l1.head);
	l1.show(l1.head);
	
	return 0;
}
