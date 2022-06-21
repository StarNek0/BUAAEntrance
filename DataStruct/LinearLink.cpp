/*
	线性表的链式存储结构
*/
#include<cstdio>
#include<iostream>
#include "LinearLink.h"

using namespace std;

// <数据结构教程>p32 创建链表
LinkList Create(int n) {
	LinkList newptr = NULL, head = NULL, tail = NULL;
	Elemtype a;
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &a);
		newptr = (LinkList)malloc(sizeof(LNode));
		newptr->data = a;
		newptr->link = NULL;

		if (head == NULL)
			head = newptr;
		else
			tail->link = newptr;
		tail = newptr;
	}
	return head;
}
void CreateTest() {
	LinkList link_list = Create(5);
	for (LinkList lnode = link_list; lnode != NULL; lnode = lnode->link) {
		cout << lnode->data << " ";
	}
	cout << endl;

}

int main() {
	CreateTest();
}