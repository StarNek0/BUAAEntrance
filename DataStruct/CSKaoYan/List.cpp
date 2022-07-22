#include "CSKaoyan.hpp"

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

int main() {
	DeleteMinTest();
}
