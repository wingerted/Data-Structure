#include <iostream>
#define MAXSIZE 10

using namespace std;

typedef struct {
	 int rear;
	 int front;
	 int size;
	 int data[MAXSIZE];
}Queue;

void InitQueue(Queue &q){
	q.rear = 0;
	q.front = 0;
	q.size = 0;
}

void EnQueue(int value, Queue &q) {	
	if (q.size == MAXSIZE) {
		cout << "队列已满" << endl;
		return;
	}
	q.data[q.rear] = value;
	q.rear = (q.rear+1) % MAXSIZE;
	q.size++;
}

int DeQueue(Queue q) {
	int value;
	value = q.data[q.front];
	q.front = (q.front+1) % MAXSIZE;
	q.size--;
	return 0;
}


int main()
{
	setlocale(LC_ALL, "");
	Queue Q;
	int x;

	InitQueue(Q);
	
	cout << "输入x的值" << endl;
	cin >> x;

	while (x != -1){
		cout << "输入x的值" << endl;
		cin >> x;	
		EnQueue(x, Q);
	}

	return 0;
}
