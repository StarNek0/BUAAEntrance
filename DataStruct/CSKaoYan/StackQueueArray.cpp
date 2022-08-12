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
void Queue3(SqQueue& Q, stack<int>& S) {
	while (Q.front != Q.rear) 
		S.push(Q.data[Q.front++]);
	
	while (!S.empty()) {
		Q.data[++Q.rear] = S.top();
		S.pop();
	}
}

/*
3．利用两个栈S1,S2来模拟一个队列，已知栈的4个运算定义如下:
	Push(S, x);//元素x入栈S
	Pop(S, x);//S出栈并将出栈的值赋给x
	StackEmpty(S);//判断栈是否为空
	StackOverflow(S);//判断栈是否满
如何利用栈的运算来实现该队列的3个运算（形参由读者根据要求自己设计）?
	Enqueue;//将元素x入队
	Dequeue;//出队，并将出队元素存储在×中
	QueueEmpty;//判断队列是否为空
*/
/*
// s1只做入队, s2只出队
// s2和s1顺序相反, 出队时将s1全部转移到s2, 入队时将s2全部转移回s1
void Enqueue(int x) {
	if (StackEmpty(s2))
		Push(s1, x);
	else {
		while(!StackEmpty(s2)){
			int x;
			Pop(s2, x);
			Push(s1, x);
		}
		Push(s1, x);
	}
}
void Dequeue(int &x) {
	if (StackEmpty(s1) && StackEmpty(s2))
		return;
	if (StackEmpty(s1))
		Pop(s2, x);
	else{
		while(!StackEmpty(s1)){
			int x;
			Pop(s1, x);
			Push(s2, x);
		}
		Pop(s2, x);
	}
}
bool QueueEmpty() {
	return StackEmpty(s1) && StackEmpty(s2);
}
*/

/*
1. 假设一个算术表达式中包含圆括号、方括号和花括号3种类型的括号, 编写一个算法来
判别表达式中的括号是否配对, 以字符“\0”作为算术表达式的结束符。
*/
bool ValidBrackets(string data) {
	stack<char> s;
	for (char c : data) {
		if (c == '(' || c == '[' || c == '{')
			s.push(c);
		switch (c){
		case ')':
			if (s.empty())
				return false;
			if (s.top() == '(')
				s.pop();
			else
				return false;
			break;
		case ']':
			if (s.empty())
				return false;
			if (s.top() == '[')
				s.pop();
			else
				return false;
			break;
		case '}':
			if (s.empty())
				return false;
			if (s.top() == '{')
				s.pop();
			else
				return false;
			break;
		}
	}
	return true;
}