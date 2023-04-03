#include <iostream>
using namespace std;

struct QueueRepr {
	int front;
	int rear;
	int queue[100];
	int max;
	int count;
};

void enqueue(QueueRepr &inst, int e) {
	inst.queue[inst.rear++] = e;
}

void dequeue(QueueRepr &inst) {
	inst.front++;
}

bool isEmpty(QueueRepr &inst) {
	return inst.front == inst.rear;
}

void display(QueueRepr &inst) {
	for (int i = inst.front; i < inst.rear; i++) {
		cout << inst.queue[i] << " ";
	}
	cout << endl;
}

void reverse(QueueRepr &inst) {
	if (isEmpty(inst)) {
		return;
	}
	
	int front = inst.queue[inst.front];
	dequeue(inst);
	
	reverse(inst);
	
	enqueue(inst, front);
}

int main() {
	QueueRepr queue;
	queue.max = 100;
	queue.front = 0;
	queue.rear = 0;
	queue.count = 0;
	
	int n;
	cout << "Enter elements, -1 to break\n";
	while (true) {
		cin >> n;
		
		if (n == -1) {
			break;
		}	
		enqueue(queue, n);
	}
	
	display(queue);
	reverse(queue);
	display(queue);
	
	return 0;
}
