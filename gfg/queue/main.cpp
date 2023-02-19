#include <stdio.h>
#include <stdlib.h>

struct QNode {
	int key;
	struct QNode* next;
};
typedef struct QNode QNode;

struct Queue {
	QNode *front, *rear;
};
typedef struct Queue Queue;

QNode *newNode(int k) {
	QNode *temp = (QNode *) malloc(sizeof(QNode));
	temp->key = k;
	temp->next = NULL;
	return temp;
}

Queue *createQueue() {
	Queue *q = (Queue *) malloc(sizeof(Queue));
	q->front = q->rear = NULL;
	return q;
}

int main(void) {
	
	return 0;
}
