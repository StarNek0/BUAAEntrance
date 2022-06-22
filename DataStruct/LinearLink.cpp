/*
	线性表的链式存储结构
*/
#include<cstdio>
#include<cassert>
#include<iostream>
#include "LinearLink.h"

using namespace std;

void Print(LinkList list) {
	cout << list << ": ";
	for (LinkList lnode = list; lnode != NULL; lnode = lnode->link) {
		cout << lnode->data << " ";
	}
	cout << endl;
}

// <数据结构教程>p32 创建链表
LinkList Create(int n) {
	LinkList newptr = NULL, left = NULL, right = NULL;
	ElemType a;
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &a);
		newptr = (LinkList)malloc(sizeof(LinkNode));
		newptr->data = a;
		newptr->link = NULL;

		if (left == NULL)
			left = newptr;
		else
			right->link = newptr;
		right = newptr;
	}
	return left;
}
void CreateTest() {
	LinkList link_list = Create(5);
	Print(link_list);
}

// <数据结构教程>p33 链表长度
int Length(LinkList list) {
	int len = 0;
	for (LinkList p = list; p != NULL; p = p->link) {
		len++;
	}
	return len;
}
void LengthTest() {
	LinkList link_list = Create(5);
	cout << Length(link_list) << endl;
}

// <数据结构教程>p33 是否空表
bool IsEmpty(LinkList list) {
	return list == NULL;
	// return list->link == NULL; // 如果是带头结点的链表
}

// <数据结构教程>p34 查找item
LinkList Find(LinkList list, ElemType item) {
	for (LinkList p = list; p != NULL; p = p->link)
		if (p->data == item)
			return p;
}
void FindTest() {
	LinkList link = Create(3);
	cout << link->link << endl;
	cout << Find(link, link->link->data) << endl;
	assert(link->link == Find(link, link->link->data));
}

// <数据结构教程>p34 非空链表头部插入item
void InsertLink1(LinkList& list, ElemType item) {
	LinkList newptr = (LinkList)malloc(sizeof(LinkNode));
	newptr->data = item;
	newptr->link = list;
	list = newptr;
}
void InsertLink1Test() {
	LinkList list = Create(3);
	Print(list);
	InsertLink1(list, 999);
	Print(list);
}

// <数据结构教程>p35 非空链表尾部插入item
void InsertLink2(LinkList list, ElemType item) {
	LinkList p = list;
	while (true)
		if (p->link != NULL) {
			p = p->link;
		}
		else {
			LinkList newptr = (LinkList)malloc(sizeof(LinkNode));
			newptr->data = item;
			newptr->link = NULL;
			p->link = newptr;
			break;
		}
}
void InsertLink2Test() {
	LinkList list = Create(3);
	Print(list);
	InsertLink2(list, 999);
	Print(list);
}

// <数据结构教程>p35 可能空的链表, 在q点后面追加item
void InsertLink3(LinkList& list, LinkList q, ElemType item) {
	LinkList newptr = (LinkList)malloc(sizeof(LinkNode));
	newptr->data = item;

	if (list == NULL) {
		list = newptr;
		newptr->link = NULL;
	}
	else {
		newptr->link = q->link;
		q->link = newptr;
	}
}
void InsertLink3Test() {
	LinkList list = Create(3);
	Print(list);
	InsertLink3(list,list->link, 999);
	Print(list);
}

int main() {
	InsertLink3Test();
}