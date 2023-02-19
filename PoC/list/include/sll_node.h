#ifndef SLL_NODE_H
#define SLL_NODE_H
typedef struct NODE {
	struct NODE *link;
	int         value;
} Node;

int sll_insert(Node **rootp, int new_value);

#endif

