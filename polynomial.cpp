#include<iostream>
using namespace std;
struct poli{
	int cof;
	int pow;
	struct poli * next;
	poli(int t_cof,int t_pow)
	{
		cof=t_cof;
		pow=t_pow;
		next=NULL;	
	} 
};
class polino{
	public:
	struct poli* head;
		add_equ(int t_cof,int t_pow)
		{
			struct poli* newpoli = new poli(t_cof,t_pow);
			
			if(!head)
			{
				head=newpoli;
			}
			else
			{
				struct poli* current = head;
				while(current->next)
				{
					current=current->next;
				}
				current->next=newpoli;
			}
	}
	
	show()
		{
			struct poli* current = head;
			while(current)
			{
				
				cout<<current->cof<<"x"<<"^"<<current->pow;
				current=current->next;
				if(current)
				cout<<"+";
				
			}
			cout<<endl<<"--------------------"<<endl;
		}
polino operator +(class polino p2) {
    struct poli* current = head;
    struct poli* current2 = p2.head;
    polino p3;
    struct poli* current3 = NULL;

    while (current != NULL || current2 != NULL) {
        struct poli* newpoli = new poli(0, 0);

        if (current == NULL) {
            newpoli->cof = current2->cof;
            newpoli->pow = current2->pow;
            current2 = current2->next;
        }
        else if (current2 == NULL) {
            newpoli->cof = current->cof;
            newpoli->pow = current->pow;
            current = current->next;
        }
        else {
            if (current->pow == current2->pow) {
                newpoli->cof = current->cof + current2->cof;
                newpoli->pow = current->pow;
                current = current->next;
                current2 = current2->next;
            }
            else if (current->pow > current2->pow) {
                newpoli->cof = current->cof;
                newpoli->pow = current->pow;
                current = current->next;
            }
            else {
                newpoli->cof = current2->cof;
                newpoli->pow = current2->pow;
                current2 = current2->next;
            }
        }

        if (current3 == NULL) {
            p3.head = newpoli;
            current3 = p3.head;
        }
        else {
            current3->next = newpoli;
            current3 = current3->next;
        }
    }

    return p3;
}

};
int main()
{
polino p1,p2,p3;
p1.add_equ(2,2);
p1.add_equ(3,1);
p1.add_equ(1,0);
p1.show();
p2.add_equ(2,2);
p2.add_equ(1,1);
p2.add_equ(4,0);
p2.show();
p3=p1+p2;
//head=p1+p2;
//p1+p2;
p3.show();
return 0;	
}
