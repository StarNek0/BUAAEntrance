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

