//postfix evaluation

#include<stdio.h>
#define size 20

int top=-1,stack[size];
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

int isoperator(char symbol) {  
    if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/') {  
        return 1;  
    }  
    return 0;  
}  

int evaluate(char *exp)
{
	int i=0,op1,op2,result;
	char symbol=exp[i];
	
	while(symbol!='#')
	{
		if (symbol >= '0' && symbol <= '9') {  
            int num = symbol - '0';  
            push(num);  
        }  
		else if(isoperator(symbol))
		{
			op2=pop();
			op1=pop();
			switch(symbol)
			{
				case '+' : result=op1 + op2;break;
				case '-' : result=op1-op2;break;
				case '*' : result=op1*op2;break;
				case '/' : result=op1/op2;	
			}		
			push(result);
		}	
		i++;
		symbol=exp[i];
	}
	result=pop();
	return(result);
}

main()
{
	char expression[] = "2 4 + 6 2 / - #";  
    int result = evaluate(expression);  
	printf("Result= %d\n", result);  
	return 0;
}
