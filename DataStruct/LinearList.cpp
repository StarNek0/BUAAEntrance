#include<cstdio>
#include<iostream>
using namespace std;

const int MaxSize = 10;
typedef int ElemType;

// p22 在长度为n的线性表A的第i个位置插入一个新元素item
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



int main() {
	insert_list_test();
}