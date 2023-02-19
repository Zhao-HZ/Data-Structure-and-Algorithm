#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


int main(void) {
	node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 70);
    root = insert(root, 80);
  
 	print_tree(root); 
	printf("\n");
}
