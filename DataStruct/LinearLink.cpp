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
	for (LinkList lnode = list; lnode != NULL; lnode = lnode->next) {
		cout << lnode->data << " -> ";
	}
	cout << "NULL" << endl;
}

LinkList CreateListByArray(ElemType A[], int n) {
	LinkList list = (LinkList)malloc(sizeof(LinkNode));
	LinkList p = list;
	if (list == NULL)
		return list;

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			p->data = A[i];
			p->next = NULL;
			continue;
		}

		LinkList newptr = (LinkList)malloc(sizeof(LinkNode));
		if (newptr == NULL)
			break;
		newptr->data = A[i];
		newptr->next = NULL;
		p->next = newptr;
		p = p->next;
	}

	return list;
}

// <数据结构教程>p32 创建链表
LinkList Create(int n) {
	LinkList newptr = NULL, left = NULL, right = NULL;
	ElemType a;
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &a);
		newptr = (LinkList)malloc(sizeof(LinkNode));
		newptr->data = a;
		newptr->next = NULL;

		if (left == NULL)
			left = newptr;
		else
			right->next = newptr;
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
	for (LinkList p = list; p != NULL; p = p->next) {
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
	for (LinkList p = list; p != NULL; p = p->next)
		if (p->data == item)
			return p;
	return NULL;
}
void FindTest() {
	LinkList link = Create(3);
	cout << link->next << endl;
	cout << Find(link, link->next->data) << endl;
	assert(link->next == Find(link, link->next->data));
}

// <数据结构教程>p34 非空链表头部插入item
void InsertLink1(LinkList& list, ElemType item) {
	LinkList newptr = (LinkList)malloc(sizeof(LinkNode));
	newptr->data = item;
	newptr->next = list;
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
		if (p->next != NULL) {
			p = p->next;
		}
		else {
			LinkList newptr = (LinkList)malloc(sizeof(LinkNode));
			newptr->data = item;
			newptr->next = NULL;
			p->next = newptr;
			break;
		}
}
void InsertLink2Test() {
	LinkList list = Create(3);
	Print(list);
	InsertLink2(list, 999);
	Print(list);
}

// <数据结构教程>p36 可能空的链表, 在指定节点指针后面追加item
void InsertLink3(LinkList& list, LinkList q, ElemType item) {
	LinkList newptr = (LinkList)malloc(sizeof(LinkNode));
	newptr->data = item;

	if (list == NULL) {
		list = newptr;
		newptr->next = NULL;
	}
	else {
		newptr->next = q->next;
		q->next = newptr;
	}
}
void InsertLink3Test() {
	LinkList list = Create(3);
	Print(list);
	InsertLink3(list, list->next, 999);
	Print(list);
}

// <数据结构教程>p36 在指定序号后面追加item
bool InsertLink4(LinkList list, int i, ElemType item) {
	int n = 1;
	for (LinkList p = list; p->next != NULL; p = p->next) {
		if (n == i) {
			LinkList newptr = (LinkList)malloc(sizeof(LinkNode));
			newptr->data = item;
			newptr->next = p->next;
			p->next = newptr;
			return true;
		}
		n++;
	}
	return false;
}
void InsertLink4Test() {
	LinkList list = Create(3);
	Print(list);
	InsertLink4(list, 1, 999);
	Print(list);
}

// <数据结构教程>p37 在非递减链表中追加item
void InsertLink5(LinkList& list, ElemType item) {
	LinkList p = list;
	while (p->next != NULL) {
		if (item > p->data)
			break;
		else
			p = p->next;
	}

	LinkList newptr = (LinkList)malloc(sizeof(LinkNode));
	newptr->data = item;
	newptr->next = p->next;
	p->next = newptr;
}
void InsertLink5Test() {
	LinkList list = Create(3);
	Print(list);
	InsertLink5(list, 2);
	Print(list);
}

// <数据结构教程>p38 知道前驱节点r的情况下删除节点q
void DeleteLink1(LinkList& list, LinkList r, LinkList q) {
	if (q == list)
		list = list->next;
	else
		r->next = r->next->next;
	free(q);
}
void DeleteLink1Test() {
	LinkList list = Create(3);
	Print(list);
	DeleteLink1(list, list, list->next);
	Print(list);
}

// <数据结构教程>p38 不知道前驱节点的情况下删除节点q
void DeleteLink2(LinkList& list, LinkList q) {
	if (q == list)
		list = list->next;
	else {
		LinkList p = list;
		while (p->next != NULL) {
			// 找到q的前驱节点p
			if (p->next == q) {
				p->next = q->next; // 移除q
				free(q);
				break;
			}
			else
				p = p->next;
		}
	}
}
void DeleteLink2Test() {
	LinkList list = Create(3);
	Print(list);
	DeleteLink2(list, list->next);
	Print(list);
}

// <数据结构教程>p39 销毁链表
void DeleteList(LinkList& list) {
	LinkList p = list;
	while (p != NULL) {
		list = p->next;
		free(p);
		p = list;
	}
}

// <数据结构教程>p39 删除所有值为item的节点
void DeleteItem(LinkList& list, ElemType item) {
	if (list == NULL) {
		return;
	}
	// 判断与删除除了第一个节点以外的值为item的节点
	for (LinkList p = list; p->next != NULL;) {
		if ((p->next)->data == item) {
			LinkList tmp = p->next; // 临时变量, 暂存待删除的节点
			p->next = p->next->next;
			free(tmp);
		}
		else {
			p = p->next;
		}
	}
	// 判断第一个节点是否等于item
	if (list->data == item) {
		LinkList tmp = list;
		list = list->next;
		free(tmp);
	}
}
void DeleteItemTest() {
	ElemType A[5] = { 1,2,2,2,4 };
	LinkList list = CreateListByArray(A, 5);
	Print(list);
	DeleteItem(list, 2);
	Print(list);
	DeleteItem(list, 1);
	Print(list);
}

// <数据结构教程>p40 逆转链表
void Invert(LinkList& list) {
	LinkList p, q, r;
	p = list;
	q = NULL;
	while (p != NULL) {
		r = q;
		q = p;
		p = p->next;
		q->next = r;
		//Print(p);
		//Print(q);
		//Print(r);
	}
	list = q;
}
void InvertTest() {
	ElemType A[5] = { 1,2,3,4,5 };
	LinkList list = CreateListByArray(A, 5);
	Print(list);
	Invert(list);
	Print(list);
}

// <数据结构教程>p42 合并链表
void Connect(LinkList lista, LinkList listb) {
	LinkList p;
	for (p = lista; p->next != NULL; p = p->next);
	p->next = listb;
}
void ConnectTest() {
	ElemType A[5] = { 1,2,3,4,5 };
	ElemType B[5] = { 6,7,8,9,10 };
	LinkList lista = CreateListByArray(A, 5);
	LinkList listb = CreateListByArray(B, 5);
	Connect(lista, listb);
	Print(lista);
}

// <数据结构教程>p42 合并升序链表
LinkList MergeList(LinkList lista, LinkList listb) {
	LinkList head = (LinkList)malloc(sizeof(LinkNode));
	LinkList p = head;
	if (!head) {
		return NULL;
	}

	LinkList pa = lista;
	LinkList pb = listb;
	while (pa != NULL && pb != NULL) {
		if (pa->data <= pb->data) {
			LinkList tmpa = pa->next;
			p->next = pa;
			p = p->next;
			pa = tmpa;
		}
		else {
			LinkList tmpb = pb->next;
			p->next = pb;
			p = p->next;
			pb = tmpb;
		}
	}
	p->next = pa ? pa : pb;
	return head->next;
}
void MergeListTest() {
	ElemType A[5] = { 1,3,5,7,9 };
	ElemType B[5] = { 1,2,4,6,8 };
	LinkList lista = CreateListByArray(A, 5);
	LinkList listb = CreateListByArray(B, 5);
	Print(lista);
	Print(listb);
	Print(MergeList(lista, listb));

	cout << endl;

	ElemType C[4] = { 2, 2, 3, 4 };
	ElemType D[4] = { 1, 1, 2, 3 };
	LinkList listc = CreateListByArray(C, 4);
	LinkList listd = CreateListByArray(D, 4);
	Print(listc);
	Print(listd);
	Print(MergeList(listc, listd));
}

// <数据结构教程>p43 复制链表
LinkList Copy(LinkList lista) {
	LinkList head = (LinkList)malloc(sizeof(LinkNode));
	LinkList pa = head;
	for (LinkList p = lista; p; p = p->next) {
		LinkList newptr = (LinkList)malloc(sizeof(LinkNode));
		newptr->data = p->data;
		newptr->next = NULL;

		pa->next = newptr;
		pa = pa->next;
	}
	return head->next;
}
void CopyTest() {
	ElemType A[5] = { 1,3,5,7,9 };
	LinkList lista = CreateListByArray(A, 5);
	Print(lista);
	LinkList listb = Copy(lista);
	Print(listb);
}

int main() {
	MergeListTest();
}