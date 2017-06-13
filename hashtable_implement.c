#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define MAXSIZE 30

struct List{
	int key;
	int value;
	struct List *next;
};

typedef struct List list_t;

list_t *HashTable[MAXSIZE];

int hashFunc(int val){
	return(val % MAXSIZE);
}

void hashInit(){
	int index = 0;
	while(index < MAXSIZE){
		list_t *new = (list_t *)malloc(sizeof(list_t));
		new->key = INT_MIN;
		new->next = NULL;
		HashTable[index] = new;
		index++;
	}
}

void hashInsert(int key, int value){
	
	list_t *new = (list_t *)malloc(sizeof(list_t));
	new->key = key;
	new->value = value;
	
	
	int index = hashFunc(key);
	if(HashTable[index]->key == INT_MIN){
		HashTable[index] = new;
		printf("Key value pair: %d %d \tInserted!\n\n", key, value);
		return;
	}
	
	list_t *head = HashTable[index];
	
	HashTable[index] = new;
	
	new->next = head;
	
}

list_t *hashSearch(int key){
	int index = hashFunc(key);
	
	list_t *node = HashTable[index];
	while((node->key != key) && (node))
		node = node->next;
	
	if(!node)
		printf("Key value pair for key = %d not found\n\n", key);	
	
	return node;
}

void hashDisplay(){
	
	int index = 0;
	list_t *new = (list_t *)malloc(sizeof(list_t));
	
	while(index < MAXSIZE){
		new = HashTable[index];
		
		if(new->key == INT_MIN){
			index++;
			continue;
		}
		printf("Index %d: ", index);
		while(new){
			printf("(Key = %d, Value = %d)==> ", new->key, new->value);
			new = new->next;
		}
		printf("Null\n");
		index++;
	}
		
}

void hashDelete(list_t *node){
	int index = hashFunc(node->key);
	
	if(HashTable[index]->key == node->key){
		HashTable[index] = HashTable[index]->next;
		return;
	}
		
	list_t *curr = HashTable[index];
	list_t *prev;
	while((curr->key != node->key) && (curr)){
		prev = curr;
		curr = curr->next;
	}
	if(curr){
		prev->next = curr->next;
		free(curr);
		printf("Key value pair successfully deleted\n\n");	
	}
	else
		printf("Key value pair not found\n\n");
		
	return;	
}

int main(){
	hashInit();
	hashInsert(20, 1);
	hashInsert(15, 1);
	hashInsert(9, 1);
	hashInsert(29, 1);
	hashInsert(36, 1);
	hashInsert(5, 1);
	hashInsert(6, 1);
	hashInsert(17, 1);
	hashInsert(7, 1);
	hashInsert(37, 1);
	hashInsert(10, 1);
	hashInsert(5, 1);
	hashDisplay();
	hashDelete(hashSearch(36));
	hashDisplay();
	return 0;
}
