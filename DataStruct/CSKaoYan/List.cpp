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

/*
7．将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表
*/

/*
8．已知在一维数组A[m +n]中依次存放两个线性表(a1, a2, a3, …, am)和(b1, b2,b3, …, bn)。试编
写一个函数，将数组中两个顺序表的位置互换，即将(b1, b2, b3, …, bn)放在(a1, a2, a3, …, am)
的前面。
*/

/*
9．线性表(a1, a2, a3, …, an)中的元素递增有序且按顺序存储于计算机内。要求设计一个算法，
完成用最少时间在表中查找数值为x的元素，若找到，则将其与后继元素位置相交换，
若找不到，则将其插入表中并使表中元素仍递增有序。
*/

int main() {
	DeleteRangeTest();
	int i = 0;
	cout << (++i)+++i;
}
