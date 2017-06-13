#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *left;
	struct Node *right;
}Binary;

Binary *insert(Binary *root, int value){
	
	if(root == NULL)
	{
		Binary *new = (Binary *)malloc(sizeof(Binary));
		new->data = value;
		new->left = new->right = NULL;
		return new;
	}
	
	if(value < root->data)	
		root->left = insert(root->left, value);
	else
		root->right = insert(root->right, value);
		
	return root;
}

void InorderTraversal(Binary *root){
	if(root == NULL)
		return;
	
	InorderTraversal(root->left);
	printf("%d ", root->data);
	InorderTraversal(root->right);
}

void PreorderTraversal(Binary *root){
	if(root == NULL)
		return;
		
	printf("%d ", root->data);
	PreorderTraversal(root->left);
	PreorderTraversal(root->right);
}

void PostorderTraversal(Binary *root){
	if(root == NULL)
		return;
		
	PostorderTraversal(root->left);
	PostorderTraversal(root->right);
	printf("%d ", root->data);
}

Binary *Search(Binary *root, int  value){
	if(root->data == value)
		return root;
	
	if(root->data > value)	
		return Search(root->left, value);
	else
		return Search(root->right, value);
			
}

Binary *Predecessor(Binary *root, int value){
	Binary *node = root;
	Binary *pre = NULL;
	
	while(node->data != value)	
		node = Search(root, value);
	
	if(node->left != NULL){	
		node = node->left;
		while(node->right != NULL)	
			node = node->right;
		pre = node;
	}
	else{
		while(root != NULL){
			if(node->data > root->data)
			{
				pre = root;
				root = root->right;
			}
			else if(node->data < root->data)
				root = root->left;
			else
				break;	
		}
	}
	
	return pre;
}

Binary *Successor(Binary *root, int value){
	Binary *node = root;
	Binary *suc = NULL;
	
	while(node->data != value)	
		node = Search(root, value);
	
	if(node->right != NULL){
		node = node->right;
		while(node->left != NULL)	
			node = node->left;
		suc = node;
	}
	else{
		while(root != NULL){
			if(node->data < root->data)
			{
				suc = root;
				root = root->left;
			}
			else if(node->data > root->data)
				root = root->right;
			else
				break;	
		}
	}
	
	return suc;		
}

Binary *deleteNode(Binary *root, int value){
	
	if(value < root->data)
		root->left = deleteNode(root->left, value);
	
	else if(value > root->data)
		root->right = deleteNode(root->right, value);
	
	else{
		if(!root->left && !root->right){
			free(root);
			return NULL;
		}
		else if(root->left && !root->right){
			Binary *temp = root->left;
			free(root);
			return temp;
		}
		else if(root->right && !root->left){
			Binary *temp = root->right;
			free(root);
			return temp;
		}
		else{
			Binary *suc = Successor(root, value);
			root->data = suc->data;
			root->right = deleteNode(root->right, suc->data);
		}	
			
	}
	return root;
}

int main(){
	
	Binary *root = NULL;
	root = insert(root, 15);
	insert(root, 9);
	insert(root, 12);
	insert(root, 23);
	insert(root, 19);
	insert(root, 10);
	insert(root, 8);
	printf("Inorder Traversal: ");
	InorderTraversal(root);
	printf("\nPreorder Traversal: ");
	PreorderTraversal(root);
	printf("\nPostorder Traversal: ");
	PostorderTraversal(root);
	printf("\n");
	Binary *a = Successor(root, 10);
	printf("a->data: %d\n", a->data);
	deleteNode(root, 9);
	printf("Inorder Traversal: ");
	InorderTraversal(root);
	printf("\nPreorder Traversal: ");
	PreorderTraversal(root);
	printf("\n");
	return 0;
}

