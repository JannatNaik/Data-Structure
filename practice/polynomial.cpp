//polynomial

#include<iostream>
using namespace std;

struct poli{
	int coef;
	int pow;
	struct poli* next;
	poli(int t_coef, int t_pow){
		coef = t_coef;
		pow = t_pow;
		next = NULL;
	}
};

class polino{
	public:
		struct poli* head;
		polino(){
			head = NULL;
		}
		
		addpoli(int coef, int pow){
			struct poli* newn = new poli(coef, pow);
			if(!head){
				head = newn;
			}
			else{
				struct poli* curr = head;
				while(curr->next){
					curr = curr->next;
				}
				curr->next = newn;
			}
		}
		
		show(){
			struct poli* curr = head;
			while(curr){
				cout<<curr->coef<<"x^"<<curr->pow;
				curr = curr->next;
				if(curr){
					cout<<"+";
				}
			}
		}
		
		polino operator+(class polino p2){
			struct poli* curr = head;
			struct poli* curr2 = p2.head;
			polino p3;
			struct poli* curr3 = NULL;
			
			while(curr != NULL || curr2 != NULL){
				struct poli* newn = new poli(0,0);
				
				if(curr == NULL){
					newn->coef = curr2->coef;
					newn->pow = curr2->pow;
					curr2 = curr2->next;
				}
				else if(curr2 == NULL){
					newn->coef = curr->coef;
					newn->pow = curr->pow;
					curr = curr->next;
				}
				else{
					if(curr->pow == curr2->pow){
						newn->coef = curr->coef + curr2->coef;
						newn->pow = curr->pow;
						curr = curr->next;
						curr2 = curr2->next;
					}
					else if(curr->pow > curr2->pow){
						newn->coef = curr->coef;
						newn->pow = curr->pow;
						curr = curr->next;
					}
					else{
						newn->coef = curr2->coef;
						newn->pow = curr2->pow;
						curr2 = curr2->next;
					}
				}
				if(p3.head == NULL){
					p3.head = newn;
					curr3 = p3.head;
				}else{
					curr3->next = newn;
					curr3 = curr3->next;
				}
			}
			return p3;
		}
};

int main(){
	polino p1, p2, p3;
	p1.addpoli(2,2);
	p1.addpoli(3,1);
	p1.addpoli(1,0);
	p1.show();
	cout<<endl;
	p2.addpoli(2,2);
	p2.addpoli(1,1);
	p2.addpoli(4,0);
	cout<<endl;
	p2.show();
	p3 = p1 + p2;
	cout<<endl;
	p3.show();
	
	return 0;
}
