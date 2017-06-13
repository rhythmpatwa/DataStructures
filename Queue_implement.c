#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 10
void Enqueue(int);
int Dequeue(void);
int queue[MAXSIZE] = {0};
static int head = 0, tail = 0;
bool full = false;

int main(void){
	Enqueue(5);
	Enqueue(8);
	Enqueue(9);
	Enqueue(10);
	Enqueue(12);
	Enqueue(20);
	Enqueue(23);
	Enqueue(45);
	Enqueue(90);
	Enqueue(7);
	
	
	
	printf("head: %d\ntail: %d\n", head, tail);
	int a = Dequeue();
	printf("a: %d\n", a);
	printf("head: %d\ntail: %d\n", head, tail);
	Enqueue(19);
	a = Dequeue();
	printf("a: %d\n", a);
	printf("head: %d\ntail: %d\n", head, tail);
	Enqueue(20);
	a = Dequeue();
	printf("a: %d\n", a);
	printf("head: %d\ntail: %d\n", head, tail);
	Enqueue(12);
	a = Dequeue();
	printf("a: %d\n", a);
	printf("head: %d\ntail: %d\n", head, tail);
}

void Enqueue(int value){
	if(full){
		printf("Cannot Insert! Queue is full");
		return;
	}
	
	queue[tail] = value;
	tail = (tail + 1) % MAXSIZE;
	
	if(tail == head){
		full = true;
		(--tail < 0) ? (tail = tail + MAXSIZE) : (tail = tail % MAXSIZE);
	}	
}

int Dequeue(void){
	if(head == tail){
		printf("Queue is empty");
		return 0;
	}
	
	full = false;
	int ret = queue[head];
	++head;	
	
	return ret;
}
