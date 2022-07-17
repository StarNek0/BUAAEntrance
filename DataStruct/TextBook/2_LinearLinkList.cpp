/*
	教材 第2章 线性表 链式存储结构
*/
#include<cstdio>
#include<cassert>
#include<iostream>
#include "2_LinearLinkList.hpp"

using namespace std;

void Print(LinkList list) {
	if (list == NULL)
		return;

	int n = 0;
	cout << list << ": ";
	for (LinkList p = list; p != nullptr; p = p->next) {
		if (p == list && n != 0) {
			cout << "[FirstNode(" << p->data << ")]" << endl;
			return;
		}
		n++;
		cout << p->data << " -> ";

	}
	cout << "NULL" << endl;
}

// 创建单向链表
LinkList CreateListByArray(ElemType A[], int n) {
	return CreateListByArray(A, n, false);
}

// 创建循环链表
LinkList CreateListByArray(ElemType A[], int n, bool loop) {
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
	if (loop)
		p->next = list;

	return list;
}

void Print(DLinkList list) {
	if (list == NULL)
		return;

	cout << list << ": ";
	// 只有头结点
	if (list->left == NULL && list->right == NULL) {
		cout << "[HeadNode] -> NULL" << endl;
		return;
	}

	// 如果有头结点, 进到数据节点
	if (list->right->left != list) {
		list = list->right;
		cout << "[HeadNode] <-> ";
	}

	int n = 0;
	for (DLinkList p = list; p != NULL; p = p->right) {
		if (p == list && n != 0) {
			cout << "[FirstNode(" << p->data << ")]" << endl;
			return;
		}
		if (p->right->left != p->left->right) {
			cout << endl << "异常: 节点关系不正确";
			return;
		}
		n++;
		cout << p->data << " <-> ";

	}
	cout << "NULL" << endl;
}

// 创建双向链表
DLinkList CreateDListByArray(ElemType A[], int n) {
	return CreateDListByArray(A, n, false, false);
}

// 创建双向循环链表
DLinkList CreateDListByArray(ElemType A[], int n, bool loop, bool head) {
	DLinkList list = (DLinkList)malloc(sizeof(DLinkNode));
	DLinkList p = list;
	if (list == NULL)
		return list;

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			p->data = A[i];
			p->left = NULL;
			p->right = NULL;
			continue;
		}
		DLinkList newptr = (DLinkList)malloc(sizeof(DLinkNode));
		if (newptr == NULL)
			break;
		newptr->data = A[i];
		newptr->left = p;
		newptr->right = NULL;

		p->right = newptr;
		p = p->right;
	}
	if (loop) {
		p->right = list;
		list->left = p;
	}
	if (head) {
		DLinkList head = (DLinkList)malloc(sizeof(DLinkNode));
		if (head == NULL)
			return head;
		head->left = NULL;
		head->right = list;
		return head;
	}

	return list;
}

// <数据结构教程>p32 创建链表
LinkList Create(int n) {
	LinkList newptr = NULL, left = NULL, right = NULL;
	ElemType a;
	for (int i = 0; i < n; i++) {
        cin >> a;
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
	LinkList newptr = (LinkList)malloc(sizeof(LinkNode));
	newptr->data = item;

	if (list == NULL || item < list->data) {
		newptr->next = list;
		list = newptr;
	}
	else {
		LinkList p = list;
		while (p->next != NULL) {
			if (item > p->data && item <= p->next->data)
				break;
			else
				p = p->next;
		}

		newptr->next = p->next;
		p->next = newptr;
	}
}
void InsertLink5Test() {
	ElemType A[5] = { 1,2,3,5 };
	LinkList list = CreateListByArray(A, 4);
	Print(list);
	InsertLink5(list, 4);
	Print(list);
	InsertLink5(list, 5);
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

// <数据结构教程>p44 利用链表排序
void LinkSort(ElemType A[], int n) {
	LinkList  list = NULL;
	for (int i = 0; i < n; i++)
	{
		InsertLink5(list, A[i]);
	}
	int i = 0;
	for (LinkList p = list; p != NULL; p = p->next)
		A[i++] = p->data;
}
void LinkSortTest() {
	ElemType A[5] = { 5, 2, 3, 1, 4 };
	LinkSort(A, 5);
	for (int i = 0; i < 5; i++)
		cout << A[i] << " ";
}

// <数据结构教程>p44 例2.4 将最大的节点移到末尾
void MoveMaxNodeToTail(LinkList& list) {
	if (list == NULL)
		return;
	if (list->next == NULL)
		return;

	// 指向最大节点的前一节点的指针
	LinkList frontptr = (LinkList)malloc(sizeof(LinkNode));

	// 指向最大节点的指针
	LinkList maxptr = (LinkList)malloc(sizeof(LinkNode));
	maxptr->next = list;

	LinkList p = list->next;
	for (; p->next != NULL; p = p->next) {
		if (p->next->data > maxptr->next->data) {
			frontptr->next = p;
			maxptr->next = p->next;
		}
	}
	// 此时p代表最后一个节点

	if (maxptr->next == p) // 头结点是最大节点
		return;
	else if (maxptr->next == list) { // 尾结点是最大节点
		LinkList tmp = list->next;
		p->next = list;
		list->next = NULL;
		list = tmp;
	}
	else {
		p->next = maxptr->next;
		frontptr->next->next = maxptr->next->next;
		maxptr->next->next = NULL;
	}
}
void MoveMaxNodeToTailTest() {
	int A[5] = { 1,2,3,4,5 };
	LinkList lista = CreateListByArray(A, 5);
	MoveMaxNodeToTail(lista);
	Print(lista);

	int B[5] = { 5, 1, 2, 3, 4 };
	LinkList listb = CreateListByArray(B, 5);
	MoveMaxNodeToTail(listb);
	Print(listb);

	int C[5] = { 5 };
	LinkList listc = CreateListByArray(C, 1);
	MoveMaxNodeToTail(listc);
	Print(listc);

	int D[5] = { 1, 2, 5, 3, 4 };
	LinkList listd = CreateListByArray(D, 5);
	MoveMaxNodeToTail(listd);
	Print(listd);
}
// <数据结构教程>p46 循环链表查找
LinkList SearchKey(LinkList list, ElemType item) {
	if (list == NULL || list->data == item)
		return list;

	LinkList p = list;
	p = list->next;
	while (p != list) {
		if (p->data == item)
			return p;
		p = p->next;
	}
	return NULL;
}
void SearchKeyTest() {
	int A[3] = { 1,2,3 };
	LinkList lista = CreateListByArray(A, 3);
	lista->next->next->next = lista;
	LinkList res = SearchKey(lista, 1);
	cout << res << endl;
}

/*
	<数据结构教程>p46 约瑟夫问题
	共有 n 个人, 从第 k 个人开始报数, 数到 m 的人出列

	在罗马人占领乔塔帕特后，39 个犹太人与Josephus及他的朋友躲到一个洞中，39个犹太人决定宁愿死也不要被人抓到，
	于是决定了一个自杀方式，41个人排成一个圆圈，由第1个人开始报数，每报数到第3人该人就必须自杀，
	然后再由下一个重新从1开始报数，直到所有人都自杀身亡为止。
	然而Josephus 和他的朋友并不想遵从，Josephus要他的朋友先假装遵从，
	他将朋友与自己安排在第16个与第31个位置，于是逃过了这场死亡游戏。
*/
void Josephus(int n, int m, int k) {
	// 创建循环链表
	LinkList list = NULL, tail = NULL;
	for (int i = n; i >= 1; i--) {
		LinkList newptr = (LinkList)malloc(sizeof(LinkNode));
		if (newptr == NULL)
			throw "申请内存失败";
		newptr->data = i;
		newptr->next = NULL;
		//newptr->next = NULL;
		if (list == NULL) {
			tail = newptr;
			list = newptr;
		}
		else {
			newptr->next = list;
			list = newptr;
		}
	}
	if (tail == NULL)
		return;
	tail->next = list;
	Print(list);

	// 设置从k开始
	LinkList p = list;
	for (int i = 1; i < k; i++)
		p = p->next;

	// 不断删除节点
	while (p->next != p) {
		for (int i = 1; i < m - 1; i++)
			p = p->next;
		cout << p->next->data << endl;
		p->next = p->next->next;
		p = p->next; // 注意这一步
		//Print(p);
	}
}
void JosephusTest() {
	Josephus(8, 4, 3);
	Josephus(41, 3, 1);
}

// <数据结构教程>p49 带头结点的双向循环链表第一个data=x的节点右边追加一个item
bool InsertD(DLinkList list, ElemType x, ElemType item) {
	if (list->right != list->left) // 判断是否有头结点
		list = list->right;
	DLinkList p = list;
	int n = 0; // 代表循环的次数, 如果p再次循环到了同一节点的时候, 用n非零来标识
	while (true) {
		if (p->data == x)
			break;
		if (p == list && n != 0)
			return false;
		p = p->right;
		n++;
	}

	DLinkList newptr = (DLinkList)malloc(sizeof(DLinkNode));
	newptr->data = item;
	newptr->left = p;
	newptr->right = p->right;
	newptr->right->left = newptr;
	p->right = newptr;
	return true;
}
void InsertDTest() {
	int A[5] = { 1,2,3 };
	DLinkList a = CreateDListByArray(A, 3, true, true);
	Print(a);
	InsertD(a, 2, 999);
	Print(a);
}

// <数据结构教程>p50 有头节点的双向循环链表删除第1个data=x的节点
bool DeleteD(DLinkList list, ElemType x) {
	DLinkList head = NULL;
	if (list->right != list->left) { // 判断是否有头结点
		head = list;
		list = list->right;
	}
	DLinkList p = list;
	int n = 0; // 代表循环的次数, 如果p再次循环到了同一节点的时候, 用n非零来标识
	while (true) {
		if (p->data == x)
			break;
		if (p == list && n != 0)
			return false;
		p = p->right;
		n++;
	}
	if (p->right == p) { // 如果仅剩1个节点
		if (head && head->right == p) {
			head->right = NULL;
		}
		free(p);
		return true;
	}

	p->left->right = p->right;
	p->right->left = p->left;
	free(p);
	return true;
}
void DeleteDTest() {
	int A[5] = { 1,2,3 };
	DLinkList a = CreateDListByArray(A, 3, true, true);
	Print(a);
	DeleteD(a, 2);
	Print(a);
	DeleteD(a, 3);
	Print(a);
	DeleteD(a, 1);
	Print(a);
}

// <数据结构教程>p53
PLinkList Attach(int coef, int exp, PLinkList r) {
	PLinkList newptr = (PLinkList)malloc((sizeof(PLinkNode)));
	newptr->coef = coef;
	newptr->exp = exp;
	newptr->next = r;
	return newptr;
}
// TODO: <数据结构教程>p53
PLinkList PAdd(PLinkList a, PLinkList b) {
	return NULL;
}
// TODO: <数据结构教程>p54 文本文件最后n行

//int main() {
//	DeleteDTest();
//}