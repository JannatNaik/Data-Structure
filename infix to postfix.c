//infix to postfix conversion

#include<stdio.h>
#define size 20
int top, stack [30];
int isEmpty()  
{  
    return top == -1;  
} 
void push(int x)
{
	if(top>=size-1)
	{
		printf("stack overflow");
		return;
	}
	else
	{
		top++;
		stack[top]=x;
	}
}

int pop()
{
	if(top==-1)
	{
		printf("stack is empty");
		return;
	}
	else
		return(stack[top--]);
}
char peek()
{
	return(stack[top]);
}
int isoperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');   

}
int precedence(char ch)   
{   
    switch (ch)   
    {   
    case '+':   
    case '-':   
        return 1;   
  
    case '*':   
    case '/':   
        return 2;   
  
    case '^':   
        return 3;   
    }   
    return -1;   
}
infix_postfix(char *infix)
{
	char postfix[50];
	int i=0,j=0;
	puts(infix);
	while(infix[i]!='#')
	{
		if(isoperand(infix[i]))
			postfix[j++]=infix[i];
		else if(infix[i]=='(')
				push('(');
			else if(infix[i]==')')
				{
					while (!isEmpty() && peek() != '(')   
                		postfix[j++] = pop(); 	
                	if (!isEmpty() && peek() != '(')   
                		return -1;             
            		else  
                		pop();
				}	
				else
				{
					while (!isEmpty() && precedence(infix[i]) <= precedence(peek()))   
                			postfix[j++] = pop();   
					push(infix[i]);
				}
				
		
		
		i++;
		
	}
	while (!isEmpty())   
        postfix[j++] = pop();   
  
    postfix[j++] = '\0';   

	puts(postfix);
}
main()
{
	char infix[]="((x+(y*z))-w)#";
	infix_postfix(infix);
	
}
