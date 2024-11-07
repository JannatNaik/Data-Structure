//infix to postfix conversion

#include<iostream>
#include<stdlib.h>
#define size 30;
using namespace std;

int top, stack[size];

void push(int data){
	if(top >= size-1){
		cout<<"stack is overflow";
	}else{
		top = top+1;
		stack[top] = data;
	}
}

int pop(){
	if(top < 0){
		cout<<"stack is underflow";
		return 0;
	}else{
		int x = stack[top];
		top = top-1;
		return x;
	}
}

int peek(){
	return stack[top];
}

bool isempty(){
	return (top<0);
}

bool isoperand(char ch){
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int precedence(char ch){
	switch(ch){
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

infix_postfix(char *infix){
	char postfix[50];
	int i = 0, j = 0;
	puts(infix);
	while(infix[i] != '#'){
		
	}
}
