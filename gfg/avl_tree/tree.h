struct Node {
	int key;
	struct Node *left;
	struct Node *right;
	int height;
};

typedef struct Node node;

void print_tree(node * root);

int height(node *N);

int get_max(int a, int b);

node * newNode(int key);

node *rightRotate(node *y);
node *leftRotate(node *x);

int getBalance(node * N);

node *insert(node *root, int key);

node *minValuesNode(node *n);

node *deleteNode(node *root, int key);
