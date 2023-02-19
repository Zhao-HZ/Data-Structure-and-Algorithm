#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

node* newNode(int item) {
	node* temp = (node *) malloc(sizeof(node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}
void inorder(node * root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

node* insert(node* node, int key) {
	// If the tree is empty.
	if (node == NULL) {
		return newNode(key);
	}	
	if (key < node->key) {
		node->left = insert(node->left, key);
	} else if (key > node->key) {
		node->right = insert(node->right, key);
	}
	return node;
}

node *minValueNode(node * root) {
	node *current = root;
	while (current && current->left != NULL) {
		current = current->left;
	}
	return current;
}

node *deleteNode(node *root, int key) {
	if (root == NULL) {
		return root;
	} else if (key < root->key) {
		root->left = deleteNode(root->left, key);
	} else if (key > root->key){
		root->right = deleteNode(root->right, key);
	} else {
		if (root->left == NULL) {
			node *temp = root->right;
			free(root);
			return temp;
		} else if (root->right == NULL) {
			node *temp = root->left;
			free(root);
			return temp;
		} else {
			node *temp = minValueNode(root->right);
			root->key = temp->key;
			deleteNode(root->right, temp->key);
		}
	}
	return root;
}

// Use Generalized Table to print the whole tree.
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
