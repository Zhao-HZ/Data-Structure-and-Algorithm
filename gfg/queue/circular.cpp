#include <bits/stdc++.h>

using namespace std;

class Queue {
	int rear, front;
	int size, *arr;
	public:
		Queue(int s) {
			front = rear = -1;
			size = s;
			arr = new int[s];
		}
		void enQueue(int value);
		int deQueue();
		void displayQueue();
};

void Queue::enQueue(int value) {
	if ((front == 0 && rear == size - 1) ||
		(rear == (front - 1) % (size - 1))) {
		printf("Queue is Full");
		return;
	} else if (front == -1) {
		front = rear = 0;
		arr[rear] = value;
	} else if (rear == size - 1 && front != 0) {
		rear = 0;
		arr[rear] = value;
	} else {
		rear++;
		arr[rear] = value;
	}
}

int Queue::deQueue() {
		if (front == -1) {
			printf("Queue is Empty\n");
			return 0;
		}		
		int data = arr[front];
		arr[front] = -1;
		if (front == rear) {
			front = -1;
			rear = -1;
		} else if (front == size - 1) {
			front = 0;
		} else {
			front++;
		}
		return data;
}

void Queue::displayQueue() {
		if (front == -1) {
			printf("Queue is Empty");
			return ;
		}
		printf("Elements in Circular Queue are: ");
		if (rear >= front) {
			for (int i = front; i <= rear; i++) {
				printf("%d ", arr[i]);
			}
		} else {
			
		}
}
