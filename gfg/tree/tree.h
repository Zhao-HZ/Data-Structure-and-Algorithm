struct NODE {
	int key;
	struct NODE *left, *right;
};
typedef struct NODE node;

node* newNode(int item);
void inorder(node * root);
node* insert(node* node, int key);
void print_tree(node * root);
void print_tree(node *root);
node *deleteNode(node *root, int key);
