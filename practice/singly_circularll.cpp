//singly circular linked list creation, insertion (beginning, middle, end), deletion (beginning, middle, end), traversal, updation, reversal

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
		struct node * head = NULL;
		
		void addlink(int data){
			struct node* newn = new node(data);
			if(!head){
				head = newn;
				head->next = head;
			}else{
				struct node* curr = head;
				while(curr->next != head){
					curr = curr->next;
				}
				curr->next = newn;
				newn->next = head;
			}
		}
		
		void show(struct node* head){
			struct node* curr = head;
			do{
				cout<< curr->data<<" ";
				curr = curr->next;
			}while(curr != head);
		}
};

//function to insert a node at the beginning
struct node* inbeg(struct node *head, int data){
	struct node* newn = new node(data);
	if(head == NULL){
		head = newn;
		head->next = head;
	}else{
		struct node* curr = head;
		while(curr->next != head){
			curr = curr->next;
		}
		curr->next = newn;
		newn->next = head;
		head = newn;
	}
	return head;
}

//function to add node at middle
struct node* inmid(struct node *head, int data, int key){
	struct node *newn = new node(data);
	if(head == NULL){
		head = newn;
		head->next = head;
	}else{
		struct node *curr = head;
		while(curr->data != key && curr->next != head){
			curr = curr->next;
		}
		if(curr->data == key){
				newn->next = curr->next;
				curr->next = newn;
		}
	}
	return head;
}

//function to insert an element at the end
struct node* inend(struct node* head, int data){
	struct node* newn = new node(data);
	if(head == NULL){
		head = newn;
		head->next = head;
	}else{
		struct node* curr = head;
		while(curr->next != head){
			curr = curr->next;
		}
		curr->next = newn;
		newn->next = head;
	}
	return head;
}

//function to delete a node from the beginning
struct node *delbeg(struct node *head){
	if(!head){
		cout<<"list is empty";
	}else if(head->next == head){
		delete(head);
	}else{
		struct node* curr = head;
		struct node* last = head;
		while(last->next != head){
			last = last->next;
		}
		head = head->next;
		last->next = head;
		delete(curr);
	}
	return head;
}

//function for deletion at the middle of the list
struct node* delmid(struct node* head, int key){
	if(!head){
		cout<<"list is empty";
	}else if(head->next == head){
		delete(head);
	}else{
		struct node* curr = head;
		struct node* curr2;
		while(curr->next != head){
			curr = curr->next;
			if(curr->data == key){
				curr2 = curr->next;
				curr->next = curr2->next;
				delete(curr2);
			}
		}
	}
	return head;
}

//function for deletion at the end
struct node *delend(struct node* head){
	if(!head){
		cout<<"list is empty";
	}else if(head->next == head){
		delete(head);
	}else{
		struct node *curr = head;
		struct node *prev;
		while(curr->next != head){
			prev = curr;
			curr = curr->next;
		}
		prev->next = head;
		delete(curr);	
	}
	return head;
}

//function for updating a node
struct node* updatenode(struct node* head, int ndata, int key){
	if(!head){
		cout<<"list is empty";
	}else{
		struct node* curr = head;
		while(curr->next != head){
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
if (!head || head->next == head) {
        return head; // No need to reverse if the list is empty or has one node
    }
    
    struct node* prev = NULL;
    struct node* current = head;
    struct node* next;
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != head);
 
    // adjusting the links so as to make the
    // last node point to the first node
    head->next = prev;
    head = prev;

    return head;
}

int main(){
	linklist l1;
	l1.addlink(10);
	l1.addlink(20);
	l1.addlink(30);
	l1.addlink(40);
	l1.addlink(50);
	
	cout<<"linklist before: "<<endl;
	l1.show(l1.head);
	
	cout<<"\n";
	 
	cout<<"\nafter insertion at the beginning"<<endl;
	l1.head = inbeg(l1.head, 5);
	l1.show(l1.head);
	
	cout<<"\n";
	 
	cout<<"\nafter insertion at the middle"<<endl;
	l1.head = inmid(l1.head, 25, 20);
	l1.show(l1.head);
	
	cout<<"\n";
	 
	cout<<"\nafter insertion at the end"<<endl;
	l1.head = inend(l1.head, 60);
	l1.show(l1.head);
	
	cout<<"\n";
	 
	cout<<"\nafter deletion at the beginning"<<endl;
	l1.head = delbeg(l1.head);
	l1.show(l1.head);
	
	cout<<"\n";
	 
	cout<<"\nafter deletion at the middle"<<endl;
	l1.head = delmid(l1.head, 20);
	l1.show(l1.head);

	cout<<"\n";
	 
	cout<<"\nafter deletion at the end"<<endl;
	l1.head = delend(l1.head);
	l1.show(l1.head);
	
	cout<<"\n";
	 
	cout<<"\nafter updation"<<endl;
	l1.head = updatenode(l1.head, 22, 30);
	l1.show(l1.head);
	
	cout<<"\n";
	 
	cout<<"\nafter updation"<<endl;
	l1.head = reverse(l1.head);
	l1.show(l1.head);
	
	 
	return 0;
}
