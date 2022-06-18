#include<cstdio>
#include<iostream>
using namespace std;

const int MaxSize = 10;
typedef int ElemType;

// <数据结构教程>p22 在长度为n的线性表A的第i个位置插入一个新元素item
bool insert_list(ElemType A[], int& n, int i, ElemType item) {
	if (n == MaxSize || i < 1 || i > n + 1)
		return false;
	for (int j = n - 1; j >= i - 1; j--)
		A[j + 1] = A[j];
	A[i - 1] = item;
	n++;
	return true;
}
void insert_list_test() {
	ElemType A[MaxSize] = { 1,2,3 };
	int n = 3;
	insert_list(A, n, 1, 9999);
	printf("%d %d %d %d %d\n", A[0], A[1], A[2], A[3], A[4]);
}

// <数据结构教程>p23 删除第i个元素
bool delete_list(ElemType A[], int& n, int i) {
	if (i<1 || i > n)
		return false;
	for (int j = i - 1; j < n; j++)
		A[j] = A[j + 1];
	n--;
	return true;
}
void delete_list_test() {
	ElemType A[MaxSize] = { 1, 2, 3, 4, 5, 6 };
	int n = 6;
	delete_list(A, n, 2);
	printf("%d %d %d", A[0], A[1], A[2]);
}

// <数据结构教程>p24 查找
int locate(ElemType A[], int n, ElemType elem) {
	for (int i = 0; i < n; i++)
		if (A[i] == elem)
			return i + 1;
	return -1;
}
void locate_test() {
	ElemType A[MaxSize] = { 1, 2, 3, 4, 5, 6 };
	int n = 6;
	cout << locate(A, n, 3) << endl;
}

int main() {
	locate_test();
}