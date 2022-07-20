#/*
	教材 第4章 堆栈和队列 栈
*/
#include "4_Stack.hpp"

namespace ArrayStack {
	// <数据结构教程>p87 栈的一系列操作
	void Init(int& top) {
		top = -1;
	}
	bool IsEmpty(int top) {
		return top == -1;
	}
	bool IsFull(int top) {
		return top == M - 1;
	}
	bool GetTop(ElemType stack[], int& top, ElemType& item) {
		if (IsEmpty(top))
			return false;
		item = stack[top];
		return true;
	}
	bool Push(ElemType stack[], int& top, ElemType item) {
		if (IsFull(top))
			return false;
		stack[++top] = item;
		return true;
	}
	bool Pop(ElemType stack[], int& top, ElemType& item) {
		if (IsEmpty(top))
			return false;
		item = stack[top--];
		return true;
	}

	// <数据结构教程>p89 两个栈共享一个空间
	bool Push2(ElemType stack[], int top[], int i, ElemType item) {
		if (top[0] == top[1] - 1)
			return false;
		if (i == 1)
			top[0]++;
		else
			top[1]--;
		stack[top[i - 1]] = item;
		return true;
	}
	bool Pop2(ElemType stack[], int top[], int i, ElemType& item) {
		if (i == 1) {
			if (top[0] == -1)
				return false;
			item = stack[top[0]--];
			return true;
		}
		else {
			if (top[1] == 5) // 令M=5, 方便调试
				return false;
			item = stack[top[1]++];
			return true;
		}
	}
	void PushPop2Test() {
		ElemType stack[5] = {};
		int top[2] = { -1, 5 };
		Push2(stack, top, 1, 1);
		Push2(stack, top, 2, 2);
		Push2(stack, top, 1, 3);
		Push2(stack, top, 2, 4);
		Push2(stack, top, 1, 5);
		Push2(stack, top, 2, 6);
		for (ElemType item : stack)
			cout << item << " ";
		cout << endl;

		ElemType item;
		cout << top[0] << " " << top[1] << endl;
		Pop2(stack, top, 1, item);
		cout << top[0] << " " << top[1] << endl;
	}
}

// <数据结构教程>p93 栈的链式存储的一系列操作
namespace LinkStack {
	void Init(LinkNode& top) {
		top = NULL;
	}
	bool Empty(LinkNode top) {
		return top == NULL;
	}
	bool GetTop(LinkNode top, ElemType& item) {
		if (Empty(top))
			return false;
		item = top->data;
		return true;
	}
	bool Push(LinkNode& top, ElemType item) {
		LinkNode newptr = (LinkNode)malloc(sizeof(Node));
		if (!newptr)
			return false;
		newptr->data = item;
		newptr->next = top;
		top = newptr;
		return true;
	}
	bool Pop(LinkNode& top, ElemType& item) {
		if (Empty(top))
			return false;
		LinkNode p = top;
		item = top->data;
		top = top->next;
		free(p);
		return true;
	}

}

// <数据结构教程>p95 4.4.1括号匹配
bool IsBrashMatch(const char A[]) {
	LinkNode top;
	LinkStack::Init(top);
	for (int i = 0; A[i] != '\0'; i++) {
		if (A[i] == '{' || A[i] == '(') {
			LinkStack::Push(top, A[i]);
		}
		else if (A[i] == '}')
		{
			if (LinkStack::Empty(top))
				return false;
			else
			{
				ElemType item;
				LinkStack::Pop(top, item);
				if (item != '{')
					return false;
			}
		}
		else if (A[i] == ')')
		{
			if (LinkStack::Empty(top))
				return false;
			{
				ElemType item;
				LinkStack::Pop(top, item);
				if (item != '(')
					return false;
			}
		}
	}
	return true;
}
void TestIsBrashMatch() {
	vector<string> As;
	As.push_back("{}");
	As.push_back("()");
	As.push_back("{()}");
	As.push_back("{(})");

	for (string a : As) {
		cout << "Case: " << a << endl;
		cout << "IsValid: " << IsBrashMatch(a.c_str()) << endl;
		cout << "---------------------------" << endl;
	}
}

// <数据结构教程>p95 数制转换
void Conversion(int num) {
	int stack[M] = {}, top = -1;
	while (num != 0) {
		stack[++top] = num % 8;
		num = num / 8;
	}
	while (top >= 0)
		cout << stack[top--];
}
void ConversionLink(int num) {
	LinkNode stack = NULL, top = NULL;
	while (num != 0) {
		LinkNode newptr = (LinkNode)malloc(sizeof(Node));
		newptr->data = num % 8;
		newptr->next = stack;
		stack = newptr;
		num = num / 8;
	}
	for (LinkNode p = stack; p != NULL; p = p->next)
		cout << p->data;
}
void ConversionTest() {
	ConversionLink(391);
}

// <数据结构教程>p99 递归
int F(int m, int n) {
	if (m * n == 0)
		return m + n + 1;
	else
		return F(m - 1, F(m, n - 1));
}

// <数据结构教程>p100 递归的递推写法
int Reccurresive(int m, int n) {
	int stack[M] = {}, top = -1;
	while (top >= -1) {
		if (m * n != 0) {
			stack[++top] = m - 1;
			n--;
		}
		else
		{
			n = m + n + 1;
			if (top >= 0)
				m = stack[top];
			top--;
		}
	}
	return n;
}

// TODO: <数据结构教程>p101 表达式
int Eval(const char E[]) { return 0; }
int Postfix(const char E[]) { return 0; }

// TODO: <数据结构教程>p104 迷宫深搜
int Maxepath(int Maze[][100], int m, int n) { return 0; }

//int main() {
//	ConversionTest();
//}