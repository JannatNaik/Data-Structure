// Doubly linkedlist creation, insertion (beginning, middle, end), deletion (beginning, middle, end), updation, reversal


#include<iostream>
using namespace std;

struct node{
	int data;
	struct node* prev;
	struct node* next;
	node(int t_data){
		data = t_data;
		prev = NULL;
		next = NULL;
	}
};

class linklist{
	public:
		struct node* head = NULL;
		
		void addlink(int data){
			struct node* newn = new node(data);
			if(!head){
				head = newn;
			}else{
				struct node* curr = head;
				while(curr->next){
					curr = curr->next;
				}
				curr->next = newn;
				newn->prev = curr;
			}
		}
		
		void show(struct node* head){
			struct node* curr = head;
			while(curr){
				cout<<curr->data<<" ";
				curr  = curr->next;
			}
		}
};

//function to insert a node at the beginning
struct node* inbeg(struct node* head, int data){
	struct node* newn = new node(data);
	if(!head){
		head = newn;
	}else{
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
	}else{
		struct node* curr = head;
		while(curr->next){
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

//function to insert a node at the end of the list
struct node* inend(struct node* head, int data){
	struct node* newn = new node(data);
	if(!head){
		head = newn;
	}else{
		struct node* curr = head;
		while(curr->next){
			curr = curr->next;
		}
		curr->next = newn;
		newn->prev = curr;
	}
	return head;
}

//function to delete a node from the beginning of the list
struct node* delbeg(struct node* head){
	if(!head){
		cout<<"list is empty!!";
	}else if(head->next == NULL){
		delete(head);
	}else{
		struct node* curr = head;
		head = head->next;
		head->prev = NULL;
		delete(curr);
	}
	return head;
}

//function to delete a node from the middle of the list
struct node* delmid(struct node* head, int key){
	if(!head){
		cout<<"list is empty";
	}else if(head->next == NULL){
		delete(head);
	}else{
		struct node* curr = head;
		struct node* curr2;
		while(curr->next){
			curr = curr->next;
			if(curr->data == key){
				curr2 = curr->next;
				curr->next = curr2->next;
				curr2->next->prev  =curr;
				delete(curr2);
			}
		}
	}
	return head;
}

//function to delete an element from the end of the list
struct node* delend(struct node* head){
	if(!head){
		cout<<"list is empty";
	}else if(head->next == NULL){
		delete(head);
	}else{
		struct node* curr = head;
		struct node* curr2;
		while(curr->next){
			curr2 = curr;
			curr = curr->next;
		}
		curr2->next = NULL;
		curr->prev = NULL;
		delete(curr);
	}
	return head;
}

//function to update an element
struct node* update(struct node* head, int ndata, int key){
	if(!head){
		cout<<"list is empty";
	}else if(head->next == NULL){
		delete(head);
	}else{
		struct node* curr = head;
		while(curr->next){
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
        cout << "List is empty!" << endl;
        return head;
    } else {
        struct node* curr = head;
        struct node* temp = NULL;
        while (curr) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
        if (temp) {
            head = temp->prev;
        }
    }
    return head;
}

int main(){
	linklist l1;
	l1.addlink(10);
	l1.addlink(20);
	l1.addlink(30);
	l1.addlink(40);
	l1.addlink(50);
	
	cout<<"before linklist:"<<endl;
	l1.show(l1.head);
	
	cout<<"\n";
	
	cout<<"\nafter insertion at the beginning:"<<endl;
	l1.head = inbeg(l1.head, 5);
	l1.show(l1.head);
	
	cout<<"\n";
	
	cout<<"\nafter insertion at the middle:"<<endl;
	l1.head = inmid(l1.head, 32, 30);
	l1.show(l1.head);
	
	cout<<"\n";
	
	cout<<"\nafter insertion at the middle:"<<endl;
	l1.head = inend(l1.head, 60);
	l1.show(l1.head);
	
	cout<<"\n";
	
	cout<<"\nafter deletion at the beginning:"<<endl;
	l1.head = delbeg(l1.head);
	l1.show(l1.head);
	
	cout<<"\n";
	
	cout<<"\nafter deletion at the middle:"<<endl;
	l1.head = delmid(l1.head, 32);
	l1.show(l1.head);
	
	cout<<"\n";
	
	cout<<"\nafter deletion at the end:"<<endl;
	l1.head = delend(l1.head);
	l1.show(l1.head);
	
	cout<<"\n";
	
	cout<<"\nafter updation:"<<endl;
	l1.head = update(l1.head, 40, 32);
	l1.show(l1.head);
	
	cout<<"\n";
	
	cout<<"\nafter reversal:"<<endl;
	l1.head = reverse(l1.head);
	l1.show(l1.head);
	
	return 0;
}
