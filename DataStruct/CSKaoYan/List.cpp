#include "CSKaoyan.hpp"

void PrintSqList(SqList* l) {
	if (l == NULL || l->length == 0)
		return;

	cout << "[";
	for (int i = 0; i < l->length; i++)
	{
		cout << l->data[i];
		if (i != l->length - 1)
			cout << " ";
	}
	cout << "]" << endl;
}
void PrintSqList(ElemType A[], int length) {
	if (length == 0)
		return;

	cout << "[";
	for (int i = 0; i < length; i++)
	{
		cout << A[i];
		if (i != length - 1)
			cout << " ";
	}
	cout << "]" << endl;
}

/*
1．从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删元素的值。
空出的位置由最后一个元素填补，若顺序表为空，则显示出错信息并退出运行。
*/
ElemType DeleteMin(SqList* l) {
	if (l == NULL || l->length == 0)
	{
		printf("警告: 顺序表为空!");
		return 0;
	}

	ElemType min = l->data[0];
	int min_index = 0;
	for (int i = 1; i < l->length; i++)
		if (l->data[i] <= min) {
			min = l->data[i];
			min_index = i;
		}
	l->data[min_index] = l->data[l->length - 1];
	l->length--;
	return min;
}
void DeleteMinTest() {
	SqList l = { {3, 1, 2, -1, 5}, 5 };
	cout << DeleteMin(&l) << endl;
	cout << l.length << endl;
}

/*
2．设计一个高效算法，将顺序表L的所有元素逆置，要求算法的"空间"复杂度为O(1)。
*/
void Reverse(SqList* l) {
	if (l->length == 0)
		return;
	ElemType tmp;
	for (int i = 0; i < l->length / 2; i++)
	{
		tmp = l->data[i];
		l->data[i] = l->data[l->length - i - 1];
		l->data[l->length - i - i] = tmp;
	}
}
void ReverseTest() {
	SqList l = { {3, 1, 2, -1, 5}, 5 };
	PrintSqList(&l);
	Reverse(&l);
	PrintSqList(&l);
}

/*
3．对长度为n的顺序表L，编写一个时间复杂度为O(n)、空间复杂度为O(1)的算法，该算
法删除线性表中所有值为x的数据元素。
*/
void DeleteItemX(SqList* l, ElemType x) {
	if (l == NULL || l->length == 0)
		return;

	for (int i = 0; i < l->length; i++)
		if (l->data[i] == x) {
			for (int j = i; j < l->length - 1; j++)
				l->data[j] = l->data[j + 1];
			l->length--;
			return;
		}
}
void DeleteItemXTest() {
	SqList l = { {3, 1, 2, -1, 5}, 5 };
	PrintSqList(&l);
	DeleteItemX(&l, -1);
	PrintSqList(&l);
}

/*
4.从有序顺序表中删除其值在给定值s与t之间（要求s<t）的所有元素，若s或t不合理
或顺序表为空，则显示出错信息并退出运行。
*/
bool DeleteSortedRange(SqList* l, int s, int t) {
	if (s >= t) {
		printf("s或t不合理");
		return false;
	}

	for (int i = 0; i < l->length; i++) {
		if (l->data[i] >= s && l->data[i] <= t) {
			int k;
			for (k = i; k < l->length; k++)
				if (l->data[k] > t)
					break;
			// WARNING: 易错
			cout << "i = " << i << " " << "k = " << k << endl;
			for (int j = i; j < l->length - (k - i); j++)
			{
				l->data[j] = l->data[j + (k - i)];
			}
			l->length -= k - i;

			break;
		}
	}
	return true;
}
void DeleteSortedRangeTest() {
	SqList l = { {1,2,3,4,5}, 5 };
	PrintSqList(&l);
	DeleteSortedRange(&l, 2, 4);
	PrintSqList(&l);
}

/*
5.从顺序表中删除其值在给定值s与t之间（要求s<t）的所有元素，若s或t不合理
或顺序表为空，则显示出错信息并退出运行。
*/
// 注:这个解法不是最优解, 效率低
bool DeleteRange(SqList* l, int s, int t) {
	if (s >= t) {
		printf("s或t不合理");
		return false;
	}

	for (int i = 0; i < l->length; ) {
		if (l->data[i] >= s && l->data[i] <= t) {
			for (int j = i; j < l->length - 1; j++)
				l->data[j] = l->data[j + 1];
			l->length--;
		}
		else
			i++; // WARNING: 易错点
	}
	return true;
}
void DeleteRangeTest() {
	SqList l = { {3, 1, 2, -1, 5}, 5 };
	PrintSqList(&l);
	DeleteRange(&l, -1, 2);
	PrintSqList(&l);
}

/*
6．从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同。
*/
void DeleteDuplicateItem(SqList& l) {
	int k = 0;
	for (int i = 0; i < l.length - 1;)
	{
		int j;
		for (j = i + 1; j < l.length;)
			if (l.data[i] == l.data[j])
				j++;
			else
			{
				l.data[k++] = l.data[i];
				i = j;
				break;
			}
		if (j == l.length && l.data[k] != l.data[i]) {
			l.data[k++] = l.data[i];
			break;
		}

	}
	l.length = k;
}
void DeleteDuplicateItemTest() {
	SqList l = { {1, 2, 2, 3, 4, 4}, 6 };
	PrintSqList(&l);
	DeleteDuplicateItem(l);
	PrintSqList(&l);
}

/*
7．将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表
*/
SqList MergeSortedList(SqList l1, SqList l2) {
	SqList l = { {}, l1.length + l2.length };
	int i = 0, i1 = 0, i2 = 0;
	while (i1 < l1.length && i2 < l2.length) {
		if (l1.data[i1] <= l2.data[i2])
			l.data[i++] = l1.data[i1++];
		else
			l.data[i++] = l2.data[i2++];
	}
	while (i1 < l1.length)
		l.data[i++] = l1.data[i1++];
	while (i2 < l2.length)
		l.data[i++] = l2.data[i2++];
	return l;
}
void MergeSortedListTest() {
	SqList l1 = { {1, 2, 2, 3, 4, 4}, 6 };
	SqList l2 = { {1, 3, 5}, 3 };
	SqList l = MergeSortedList(l1, l2);
	PrintSqList(&l);
}

/*
8．已知在一维数组A[m +n]中依次存放两个线性表(a1, a2, a3, …, am)和(b1, b2,b3, …, bn)。试编
写一个函数，将数组中两个顺序表的位置互换，即将(b1, b2, b3, …, bn)放在(a1, a2, a3, …, am)
的前面。
*/
void ReverseA(ElemType A[], int left, int right) {
	int tmp;
	while (left < right) {
		tmp = A[left];
		A[left] = A[right];
		A[right] = tmp;
		left++;
		right--;
	}
}
void ReverseATest() {
	ElemType A[] = { 1, 2, 3, 4, 5 };
	PrintSqList(A, 5);
	ReverseA(A, 0, 4);
	PrintSqList(A, 5);
	ReverseA(A, 0, 2);
	PrintSqList(A, 5);
}
void ExchangeAmn(ElemType A[], int m, int n, int length) {
	ReverseA(A, 0, m + n - 1);
	ReverseA(A, 0, n - 1);
	ReverseA(A, n, m + n - 1);
}
void ExchangeAmnTest() {
	ElemType A[] = { 1, 2, 3, 4, 5 };// a1, a2, a3, b1, b2
	ExchangeAmn(A, 3, 2, 5);
	PrintSqList(A, 5);
}
/*
9．线性表(a1, a2, a3, …, an)中的元素递增有序且按顺序存储于计算机内。要求设计一个算法，
完成用最少时间在表中查找数值为x的元素，若找到，则将其与后继元素位置相交换，
若找不到，则将其插入表中并使表中元素仍递增有序。
*/
void Insert9(SqList& l, int index, int x) {
	for (int i = l.length; i > index; i--)
		l.data[i] = l.data[i - 1];
	l.data[index] = x;
	l.length++;
}
void Solve9(SqList& l, int x) {
	if (x < l.data[0]) {// x小于第一个元素, 头部追加
		Insert9(l, 0, x);
	}
	else if (x > l.data[l.length - 1])
		l.data[l.length++] = x; // x大于最后一个元素, 尾部追加
	else if (x == l.data[l.length - 1])
		return; // x恰好等于最后一个元素, 但没有后继元素, 这是未定义的情况, 直接返回
	else
	{
		// 二分法
		int left = 0, right = l.length - 1;
		int mid;
		while (left <= right) {
			if (left == right && l.data[left] != x) { // 找到了插入元素的点
				if (l.data[left] < x) { // 右侧插入
					Insert9(l, left + 1, x);
					return;
				}
				else // 左侧插入
				{
					Insert9(l, left, x);
					return;
				}
			}
			mid = (left + right) / 2;
			if (x == l.data[mid]) { // 找到了交换元素的点
				int tmp = l.data[mid];
				l.data[mid] = l.data[mid + 1];
				l.data[mid + 1] = tmp;
				return;
			}
			else if (left == mid) // 如果left与mid相等, 且不等于x, 应该直接让left右移, 而不是用mid赋值, 否则会永远循环
				left++;
			else if (x < l.data[mid])
				right = mid;
			else
				left = mid;
		}
	}
}
void Solve9Test() {
	SqList l = { {1,3,5,7,10}, 5 };
	Solve9(l, 11);
	Solve9(l, 8);
	Solve9(l, 6);
	Solve9(l, 4);
	Solve9(l, 2);
	PrintSqList(&l);
}

int main() {
	Solve9Test();
}
