#include <stdio.h>
#include <stdlib.h>

struct NODE {
	int data;
	struct NODE *next;
};
typedef struct NODE Node;


void push(Node ** head_ref, int new_data) {
	Node *new_node = (Node *) malloc(sizeof(Node));
	if (new_node == NULL) return;
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}

void insertAfter(Node *pre_node, int new_data) {
	if (pre_node == NULL) return; 
	Node *new_node = (Node *) malloc(sizeof(Node));
	new_node->data = new_data;
	new_node->next =  pre_node->next;
	pre_node->next = new_node;
}

void append(Node ** head_ref, int new_data) {
	Node *new_node = (Node *) malloc(sizeof(Node));
	if (new_node == NULL) return;
	new_node->data = new_data;
	new_node->next = NULL;
	if (*head_ref == NULL) {
		*head_ref = new_node;
		return;
	}
	Node *last = *head_ref;
	while (last->next != NULL) {
		last = last->next;
	}
	last->next = new_node;
	return;
}

void delete_node(Node **head_ref, int key) {
	Node *tmp = *head_ref;
	Node *prev = NULL;
	if (tmp != NULL && tmp->data == key) {
		*head_ref = tmp->next;
		free(tmp);
		return ;
	}
	while (tmp != NULL && tmp->data != key) {
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL) {
		return ;
	}
	prev->next = tmp->next;
	free(tmp);
	return ;
}

void free_all(Node *node) {
	while (node != NULL) {
		Node *cur = node;
		node = node->next;
		free(cur);
	}
}

// Pass the header to it.
void print_list(Node *node){
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

int get_length(Node *node) {
	int len = 0;
	if (node == NULL) return len;
	while (node != NULL) {
		node = node->next;
		len++;
	}
	return len;
}

int main(void){ 
	Node *head = NULL;
	append(&head, 6);
	insertAfter(head, 8);
	append(&head, 7);
	insertAfter(head->next, 1);
	insertAfter((head->next)->next, 100);
	delete_node(&head, 7);
	insertAfter((head->next)->next, 200);
	print_list(head);
	printf("len = %d\n", get_length(head));
	free_all(head);
	return 0;
}
