/*
	线性表的顺序存储结构
*/
#include<cstdio>
#include<iostream>
using namespace std;

const int MaxSize = 10;
typedef int ElemType;

// <数据结构教程>p22 在长度为n的线性表A的第i个位置插入一个新元素item
bool InsertList(ElemType A[], int& n, int i, ElemType item) {
	if (n == MaxSize || i < 1 || i > n + 1)
		return false;
	for (int j = n - 1; j >= i - 1; j--)
		A[j + 1] = A[j];
	A[i - 1] = item;
	n++;
	return true;
}
void InsertListTest() {
	ElemType A[MaxSize] = { 1,2,3 };
	int n = 3;
	InsertList(A, n, 1, 9999);
	printf("%d %d %d %d %d\n", A[0], A[1], A[2], A[3], A[4]);
}

// <数据结构教程>p23 删除第i个元素
bool DeleteList(ElemType A[], int& n, int i) {
	if (i<1 || i > n)
		return false;
	for (int j = i - 1; j < n; j++)
		A[j] = A[j + 1];
	n--;
	return true;
}
void DeleteListTest() {
	ElemType A[MaxSize] = { 1, 2, 3, 4, 5, 6 };
	int n = 6;
	DeleteList(A, n, 2);
	printf("%d %d %d", A[0], A[1], A[2]);
}

// <数据结构教程>p24 查找
int Locate(ElemType A[], int n, ElemType elem) {
	for (int i = 0; i < n; i++)
		if (A[i] == elem)
			return i + 1;
	return -1;
}
void LocateTtest() {
	ElemType A[MaxSize] = { 1, 2, 3, 4, 5, 6 };
	int n = 6;
	cout << Locate(A, n, 3) << endl;
}

// <数据结构教程>p25 去重 O(n^2)
void Purge(ElemType A[], int& n) {
	int i = 0, j;
	while (i < n) {
		j = i + 1;
		while (j < n) {
			if (A[i] == A[j])
				DeleteList(A, n, j + 1);
			else
				j++;
		}
		i++;
	}
	// 下面这种写法是错误的
	// 因为j不应该无条件++: 执行DeleteList的这个分支不应该++
	//for (int i = 0; i < n; i++)
	//	for (int j = i + 1; j < n; j++)
	//		if (A[i] == A[j])
	//			DeleteList(A, n, j + 1);
}
void PurgeTest() {
	ElemType A[MaxSize] = { 1, 2, 3, 3, 3, 5, 6, 7, 6, 1 };
	int n = 10;
	Purge(A, n);
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl;
}

// <数据结构教程>p25 选择排序
void SelectSort(ElemType A[], int n) {
	for (int i = 0; i < n; i++) {
		int min_value = A[i];
		int min_index = i;
		for (int j = i + 1; j < n; j++) {
			if (A[j] < min_value) { // 通过比较, 确定后n-i+i个元素中最小的值和索引
				min_value = A[j];
				min_index = j;
			}
		}
		/*
			因为 min_value 初始值是A[i]
			所以如果后n - 1 + 1个元素都比A[i]大
			那么最后 min_value 不变, 相当于自己和自己交换, 不影响结果正确性
		*/
		int tmp = A[i];
		A[i] = min_value;
		A[min_index] = tmp;
	}
}
void SelectSortTest() {
	ElemType A[MaxSize] = { 1, 2, 3, 3, 5, 6, 7, 6, 1 };
	int n = 9;
	SelectSort(A, n);
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl;
}

// <数据结构教程>p26 删除等于item的元素 O(n^2)
void DeleteItem1(ElemType A[], int& n, ElemType item) {
	for (int i = 0; i < n;)
		if (A[i] == item)
			DeleteList(A, n, i + 1);
		else
			i++;
}
void DeleteItem1Test() {
	ElemType A[MaxSize] = { 1, 2, 3, 3, 3, 5, 6, 7, 6, 1 };
	int n = 10;
	DeleteItem1(A, n, 3);
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl;
}

// <数据结构教程>p26 删除等于item的元素 O(n)
void DeleteItem2(ElemType A[], int& n, ElemType item) {
	int  k = -1;
	for (int i = 0; i < n; i++) {
		if (A[i] == item)
			k++;
		else
			A[i - k - 1] = A[i];
		n = n - k - 1;
	}
}
void DeleteItem2Test() {
	ElemType A[MaxSize] = { 1, 2, 3, 3, 3, 5, 6, 7, 6, 1 };
	int n = 10;
	DeleteItem2(A, n, 3);
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl;
}

// <数据结构教程>p27 去重 O(n)
void Purge1(ElemType A[], int& n) {
	if (n == 1) {
		return;
	}
	int i = 0;
	for (int j = 1; j < n - 1; j++)
		if (A[i] != A[j])
			A[++i] = A[j];
	n = i + 1;
}
void Purge1Test() {
	ElemType A[MaxSize] = { 1, 2, 3, 3, 3, 5, 6, 7, 6, 1 };
	int n = 10;
	Purge1(A, n);
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl;
}

// <数据结构教程>p27 非递减的线性表A[], 插入元素item并保持非递减
bool InsertItem(ElemType A[], int& n, ElemType item) {
	if (n == MaxSize)
		return false;

	if (item >= A[n - 1]) {
		A[n] = item;
		n++;
	}
	else {
		int i = 0;
		while (item >= A[i])
			i++;
		InsertList(A, n, i + 1, item);
	}

	return true;
}
void InsertItemTest() {
	ElemType A[MaxSize] = { 1,2,3 };
	int n = 3;
	InsertItem(A, n, 2);
	InsertItem(A, n, 9999);
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl;
}


//int main() {
//	InsertItemTest();
//}