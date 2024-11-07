// Doubly circular linkedlist creation, insertion (beginning, middle, end), deletion (beginning, middle, end), updation, reversal

#include<iostream>
using namespace std;

struct node{
	int data;
	struct node* next;
	struct node* prev;
	node(int t_data){
		data = t_data;
		prev = NULL;
		next = NULL; 
	}
};

class linklist{
	public:
		struct node* head;
		linklist(){
			head = NULL;
		}
		
		void addlink(int data){
			struct node* newn = new node(data);
			if(head == NULL){
				head = newn;
				head->next = head;
				head->prev = head;
			}else{
				struct node* curr = head;
				while(curr->next != head){
					curr = curr->next;
				}
				curr->next = newn;
				newn->prev = curr;
				newn->next = head;
				head->prev = newn;
			}
		}
		
		void show(struct node* head){
			if(!head){
				cout<<"list is empty";
			}else{
				struct node* curr = head;
				do{
					cout<<curr->data<<" ";
					curr = curr->next;
				}while(curr != head);
			}
		}
};

//function to insert a node at beginning
struct node* inbeg(struct node* head, int data){
	struct node* newn = new node(data);
	if(!head){
		head = newn;
		head->next = head;
		head->prev = head;
	}else{
		newn->prev = head->prev;
		head->prev->next = newn;
		newn->next = head;
		head->prev = newn;
		head = newn;
	}
	return head;
}

//function to insert a node at the middle
struct node* inmid(struct node* head, int data, int key){
	struct node* newn = new node(data);
	if(!head){
		head = newn;
		head->next = head;
		head->prev = head;
	}else{
		struct node* curr = head;
		while(curr->next != head){
			curr = curr->next;
			if(curr->data == key){
				newn->next = curr->next;
				curr->next->prev = newn;
				curr->next = newn;
				newn->prev = curr;
			}
		}
		
	}
	return head;
}

//function to add node at the end of the list
struct node* inend(struct node* head, int data){
	struct node* newn = new node(data);
	if(!head){
		head = newn;
		head->next = head;
		head->prev = head;
	}else{
		struct node* curr = head;
		while(curr->next != head){
			curr = curr->next;
		}
		newn->next = head;
		head->prev = newn;
		curr->next = newn;
		newn->prev = curr;
	}
	return head;
}

//function to delete a node at the beginning
struct node* delbeg(struct node* head){
	if(!head){
		cout<<"list is empty";
	}else if(head->next == head){
		delete(head);
	}else{
		struct node* curr = head;
		struct node* curr2 = head;
		while(curr2->next != head){
			curr2 = curr2->next;
		}
		curr2->next = curr->next;
		curr->next->prev = curr2;
		head = curr->next;
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
			curr2 = curr;
			curr = curr->next;
			if(curr2->data == key){
				curr2->next = curr->next;
				curr->next->prev = curr2;
				delete(curr);
			}
		}
	}
	return head;
}

//function to delete a node at the end
struct node* delend(struct node* head){
	if(!head){
		cout<<"list is empty";
	}else if(head->next == head){
		delete(head);
	}else{
		struct node* curr = head;
		struct node* curr2;
		while(curr->next != head){
			curr2 = curr;
			curr = curr->next;
		}
		curr2->next = head;
		head->prev = curr2;
		delete(curr);
		
	}
	return head;
}

//function to update an element in the list
struct node* update(struct node* head, int ndata, int key){
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
	if (!head) {
        cout << "list is empty";
        return head;
    }

    struct node* curr = head;
    struct node* prev = NULL;
    struct node* next = NULL;
    struct node* tail = head->prev; // Get the last node to update the head later

    do {
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    } while (curr != head);

    head->next = prev;
    head->prev = tail;
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
	cout<<"befor linklist:"<<endl;
	l1.show(l1.head);
	
	cout<<"\n";
	
	cout<<"\nafter insertion at the beginning:"<<endl;
	l1.head = inbeg(l1.head, 5);
	l1.show(l1.head);
	
	cout<<"\n";
	
	cout<<"\nafter insertion at the middle:"<<endl;
	l1.head = inmid(l1.head, 25, 20);
	l1.show(l1.head);
	
	cout<<"\n";
	
	cout<<"\nafter insertion at the end:"<<endl;
	l1.head = inend(l1.head, 60);
	l1.show(l1.head);
	
	cout<<"\n";
	
	cout<<"\nafter deletion at the beginning:"<<endl;
	l1.head = delbeg(l1.head);
	l1.show(l1.head);
	
	cout<<"\n";
	
	cout<<"\nafter deletion at the middle:"<<endl;
	l1.head = delmid(l1.head, 20);
	l1.show(l1.head);
	
	cout<<"\n";
	
	cout<<"\nafter deletion at the end:"<<endl;
	l1.head = delend(l1.head);
	l1.show(l1.head);
	
	cout<<"\n";
	
	cout<<"\nafter updation:"<<endl;
	l1.head = update(l1.head, 22, 30);
	l1.show(l1.head);
	
	cout<<"\n";
	
	cout<<"\nafter reversal:"<<endl;
	l1.head = reverse(l1.head);
	l1.show(l1.head);
	
	
	return 0;
}
