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


int main() {
	ReverseTest();
}
