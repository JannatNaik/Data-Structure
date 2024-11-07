//binary search tree
#include<iostream>
using namespace std;


struct node{
	int data;
	struct node * left;
	struct node * right;
	node(int t_data){
		data = t_data;
		left = NULL;
		right = NULL;
	}
};

class tree{
	public:
	struct node * root;
	tree(){
		root = NULL;
	}
	
	add_node(int data){
		struct node *newn = new node(data);
		if(root == NULL){
			root = newn;
		}else{
			struct node * curr = root;
			if(newn->data<curr->data){
				while(curr->left){
					curr = curr->left;
				}
				curr->left = newn;
			}else if(newn->data>curr->data || newn->data == curr->data){
				while(curr->right){
					curr = curr->right;
				}
				curr->right = newn;
			}
		}
	}
	
	bool isempty(){
		return top == -1;
	}
	
	bool isfull(){
		return top == size-1;
	}
	
	void push()
};

void show(struct node * root){
	if(root == NULL){
		return;
	}else{
		cout << root->data << " ";
		show(root->left);
		show(root->right);
	}
}

int main(){
	tree t1;
	t1.add_node(50);
	t1.add_node(29);
	t1.add_node(30);
	t1.add_node(55);
	t1.add_node(88);
	t1.add_node(60);
	t1.add_node(45);
	
	show(t1.root);
	return 0;
}
