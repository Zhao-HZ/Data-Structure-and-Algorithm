#include <stdio.h>
#include <stdlib.h>
#include "./include/sll_node.h"


int sll_insert(Node **rootp, int new_value) {
	Node *current;
	Node *previous;
	Node *new;
	current = *rootp; // current is the first element after the root.
 	previous = NULL;
	
	while (current != NULL && current->value < new_value) {
		previous = current;
		current = current->link;
	}
	// It is the case when the new element is the first element.
	// after the root.
	new = (Node *) malloc(sizeof(Node));
	if (new == NULL) {
		return 0; // Fail!
	}
	new->value = new_value;
	new->link = current;
	if (previous == NULL) {
		*rootp = new;
	} else {
		previous->link = new;
	}
	return 1; // Success
}
