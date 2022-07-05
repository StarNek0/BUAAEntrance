#include "4_Queue.hpp"

// <数据结构教程>p109 队列的一系列操作
void InitialQ(int& front, int& rear) {
	front = -1;
	rear = -1;
}

bool EmptyQ(int front, int rear) {
	return front == rear;
}

bool GetQ(int Queue[], int front, int rear, int& item) {
	if (EmptyQ(front, rear))
		return false;
	item = Queue[front + 1];
	return 1;
}

bool AddQ(int Queue[], int& rear, int item) {
	if (rear == M - 1)
		return false;
	Queue[++rear] = item;
	return true;
}

bool DelQ(int Queue[], int& front, int rear, int& item) {
	if (EmptyQ(front, rear))
		return false;
	item = Queue[++front];
	return true;
}

// <数据结构教程>p112 循环队列的入队
int AddCQ(int Queue[], int front, int& rear, int item) {
	if ((rear + 1) % M == front)
		return false;
	Queue[(++rear) % M] = item;
	return true;
}

// <数据结构教程>p113 循环队列的出队
int DeleCQ(int Queue[], int& front, int rear, int& item) {
	if (front == rear)
		return false;
	front = (front + 1) % M;
	item = Queue[front];
	return true;
}

// <数据结构教程>p114 队列的链式存储的一系列操作
void InitialLink(LinkNode& front, LinkNode& rear) {
	front = rear = NULL;
}

bool Empty(LinkNode front) {
	return front == NULL;
}

bool GetLinkQ(LinkNode front, int& item) {
	if (Empty(front))
		return false;
	item = front->data;
	return true;
}

bool AddLinkQ(LinkNode& front, LinkNode& rear, int& item) {
	LinkNode newptr = (LinkNode)malloc(sizeof(Node));
	newptr->data = item;
	newptr->next = NULL;
	if (front == NULL)
		front = newptr;
	else
		rear->next = newptr;
	rear = newptr;
	return true;
}

bool DelLinkQ(LinkNode& front, int& item) {
	if (Empty(front))
		return false;
	LinkNode p = front;
	item = front->data;
	front = front->next;
	free(p);
	return true;
}

void DestoryQ(LinkNode& front, LinkNode& rear) {
	while (front) {
		rear = front->next;
		free(front);
		front = rear;
	}
}