#include "CSKaoyan.hpp"

/*
4.设单链表的表头指针为L，结点结构由data和next两个域构成，其中data域为字符型。
试设计算法判断该链表的全部n个字符是否中心对称。例如xyx、xyyx都是中心对称。
*/

bool Stack4(LinkList l) {
	ElemType stack[MaxSize] = {};
	int top = -1;

	for (LinkList p = l; p != NULL; p = p->next)
		stack[++top] = p->data;

	LinkList p = l;
	while (top >= 0) {
		if (p->data != stack[top--])
			return false;
		p = p->next;
	}
	return true;
}

/*
1. 若希望循环队列中的元素都能得到利用, 则需设置一个标志域 tag, 并以 tag 的值为 О
或 1 来区分队头指针 front 和队尾指针 rear 相同时的队列状态是 “空” 还是 “满”。
试编写与此结构相应的入队和出队算法。
*/
int tag = 0; // Q.tag;
int EnQuquq(SqQueue& Q, ElemType x) {
	if (Q.front == Q.rear && tag == 1)
		return 0;
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MaxSize;
	tag = 1;
	return 1;
}
int DeQueue(SqQueue& Q, ElemType& x) {
	if (Q.front == Q.rear && tag == 0)
		return 0;
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	tag = 0;
	return 1;
}

/*
2. Q是一个队列，S是一个空栈，实现将队列中的元素逆置的算法。
*/
int Queue3(SqQueue& Q, stack<int>& S) {
	while (Q.front != Q.rear) 
		S.push(Q.data[Q.front++]);
	
	while (!S.empty()) {
		Q.data[++Q.rear] = S.top();
		S.pop();
	}
}