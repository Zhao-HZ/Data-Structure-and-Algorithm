#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void print_tree(node * root) {
	printf("%d", root->key);
	if (root->left != NULL) {
		printf("(");
		print_tree(root->left);
		if (root->right == NULL) {
			printf(")");
		}
	}	
	if (root->right != NULL) {
		if (root->left == NULL) {
			printf("(");
		} 
		printf(", ");
		print_tree(root->right);
		printf(")");
	}
}

int get_max(int a, int b) {
	return (a > b ? a : b);
}

int height(node *N) {
	if (N == NULL) return 0;
	return N->height;
}

int getBalance(node *N) {
	return height(N->left) - height(N->right);
}

node *rightRotate(node *y) {
	node *x = y->left;
	node *T2 = x->right;
	x->right = y;
	y->left = T2;
	y->height = get_max(height(y->left), height(y->right)) + 1;
	x->height = get_max(height(x->left), height(x->right)) + 1;
	return x;
}

node* newNode(int key) {
	node *n = (node *) malloc(sizeof(struct Node));
	n->key = key;
	n->left = NULL;
	n->right = NULL;
	n->height = 1;
	return n;
}

node *leftRotate(node *x) {
	node *y = x->right;
	node *T2 = y->left;
	y->left = x;
	x->right = T2;
	x->height = get_max(height(x->left), height(x->right)) + 1;
	y->height = get_max(height(y->left), height(y->right)) + 1;
	return y;
}

node* insert(node *root, int key) {
	if (root == NULL) {
		return newNode(key);
	}
	
	if (key < root->key) { 
 		root->left = insert(root->left, key);
	} else if (key > root->key) {
		root->right= insert(root->right, key);
	} else {
		return root;
	}
	root->height = 1 + get_max(height(root->left), height(root->right));
	int balance = getBalance(root);

	if (balance > 1 && key < root->left->key) {
		return rightRotate(root);
	}
	if (balance < -1 && key > root->right->key) {
		return leftRotate(root);
	}	
	if (balance > 1 && key > root->left->key) {
		root->left = leftRotate(root->left);
	} 
	if (balance < -1 && key > root->right->key) {
		root->right = rightRotate(root->right);
	}
	return root;
}

node *minValuesNode(node *n) {
	node *current = n;
	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}

node *deleteNode(node *root, int key) {
	if (root == NULL) return root;

	if (key < root->key) {
		root->left = deleteNode(root->left, key);
	} else if (key > root->key) {
		root->right = deleteNode(root->right, key);
	} else {  
		// Node with only one child or no child.
		if ((root->left = NULL) || (root->right == NULL)) {
			node *temp = root->left ?
				root->left : root->right;	
			if (temp == NULL) { // No child case.
				temp = root;
				root = NULL;
			} else { // One child case.
				*root = *temp;
			}
			free(temp);	
		} else {
			node *temp = minValuesNode(root->right);
			root->key = temp->key;
			root->right = deleteNode(root->right, temp->key);
		}
	}
	if (root == NULL) return root;
	root->height = 1 + get_max(height(root->left),
							height(root->right));
	int balance = getBalance(root);
	return root;
}
