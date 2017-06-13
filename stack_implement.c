#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50

int pop();
void push(int);

int stack[MAXSIZE] = {0};
static int stacktop = -1;

int main(void){
	
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	int a = pop();
	printf("%d\n", a);
	a = pop();
	printf("%d\n", a);
}

int pop(){
	if(!stacktop){
		printf("Stack is empty");
		return 0;
	}
	return stack[stacktop--];
}

void push(int value){
	
	if(stacktop >= MAXSIZE){
		printf("Stack is full");
		return;
	}
	++stacktop;
	stack[stacktop] = value;
	
}
