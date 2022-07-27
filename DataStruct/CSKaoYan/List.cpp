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
1.从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删元素的值。
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
2.设计一个高效算法，将顺序表L的所有元素逆置，要求算法的"空间"复杂度为O(1)。
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
3.对长度为n的顺序表L，编写一个时间复杂度为O(n)、空间复杂度为O(1)的算法，该算
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
6.从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同。
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
7.将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表
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
8.已知在一维数组A[m +n]中依次存放两个线性表(a1, a2, a3, …, am)和(b1, b2,b3, …, bn)。试编
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
9.线性表(a1, a2, a3, …, an)中的元素递增有序且按顺序存储于计算机内。要求设计一个算法，
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

void Print(LinkList list) {
	if (list == NULL)
		return;

	int n = 0;
	cout << list << ": ";
	for (LinkList p = list; p != nullptr; p = p->next) {
		if (p == list && n != 0) {
			cout << "[FirstNode(" << p->data << ")]" << endl;
			return;
		}
		n++;
		cout << p->data << " -> ";

	}
	cout << "NULL" << endl;
}

/*
1.设计一个递归算法，删除不带头结点的单链表工中所有值为x的结点。
*/

void DeleteX(LinkList& l, ElemType x) {
	LNode* p;
	if (l == NULL)
		return;
	if (l->data == x) {
		p = l;
		l = l->next;
		//free(p); // _CrtIsValidHeapPointer 内存不能跨模块分配和释放
		DeleteX(l, x);
	}
	else
		DeleteX(l->next, x);
}
void DeleteXTest() {
	LNode l3 = { 3, NULL };
	LNode l2 = { 2, &l3 };
	LNode l1 = { 1, &l2 };

	LNode l0 = { 0, &l1 };
	LinkList l = &l0;

	Print(l);
	DeleteX(l, 2);
	DeleteX(l, 3);
	DeleteX(l, 0);
	Print(l);
}

/*
2.在带头结点的单链表工中，删除所有值为x的结点，并释放其空间，假设值为的结点
不唯一，试编写算法以实现上述操作。
*/
void DeleteX1(LinkList& l, ElemType x) {
	if (l == NULL)
		return;
	LinkList p = l;
	while (p != NULL && p->next != NULL) {
		if (p->next->data == x) {
			LinkList q = p->next;
			p->next = p->next->next;
			//free(p); // _CrtIsValidHeapPointer 内存不能跨模块分配和释放
		}

		p = p->next;
	}
}

/*
3.设L为带头结点的单链表，编写算法实现从尾到头反向输出每个结点的值。
WARNING: 需要复习
*/
void R_Print(LinkList l) {
	if (l->next != NULL)
		R_Print(l->next);
	if (l != NULL)
		printf("%d ", l->data);
}

/*
4.试编写在带头结点的单链表工中删除一个最小值结点的高效算法(假设最小值结点是唯
一的)。
WARNING: 需要复习
*/
void DeleteLinkMin(LinkList& l) {
	LinkList pre = l, p = l->next;
	LinkList minpre = pre, minp = p;
	while (p != NULL) {
		if (p->data < minp->data) {
			minp = p;
			minpre = pre;
		}
		pre = p; p = p->next;
	}
	minpre->next = minp->next;
	//free(minp);
}

/*
5.试编写算法将带头结点的单链表就地逆置，所谓“就地”是指辅助空间复杂度为O(1)。
*/
void ReverseLink(LinkList& l) {
	if (l->next == NULL || l->next->next == NULL)
		return;
	LinkList pre = l->next, p = pre->next, tmp = NULL;
	// 令pre是p的前一结点
	while (p != NULL) {
		l->next = p; // 头结点指向p
		pre->next = NULL; // 断开pre和p
		tmp = p->next; // 保存p的下一结点
		p->next = pre; // 断开p和下一结点的连接, 转而指向前一节点pre

		pre = p; // 把pre向后移
		p = tmp; // 把p向后移
	}
}

/*
6.有一个带头结点的单链表L，设计一个算法使其元素递增有序
*/
void SortLink(LinkList& l) {
	queue<LinkList> q;
	while (l->next != NULL) {
		LinkList minpre = l, min = l->next;
		LinkList pre = l, p = l->next;
		while (p != NULL) {
			if (p->data < min->data) { // 更新和保存最小值的结点及其前缀
				minpre = pre;
				min = p;
			}
			pre = pre->next;
			p = p->next; // 更新链表指针
		}
		q.push(min); // 每一趟将最小值加入队列, 最终队列是递增的
		minpre->next = min->next;
	}

	// 从队列依次取出头部元素更新到头结点后面
	LinkList p = l;
	while (!q.empty()) {
		p->next = q.front();
		p = p->next;
	}
	p->next = NULL;
}

/*
7.设在一个带表头结点的单链表中所有元素结点的数据值无序，试编写一个函数，删除表
中所有介于给定的两个值（作为函数参数给出)之间的元素的元素（若存在)。
*/
void DeleteLinkByRange(LinkList& l, ElemType left, ElemType right) {
	LinkList pre = l, p = l->next;
	while (p != NULL) {
		if (left <= p->data && p->data <= right) {
			pre->next = p->next;
			p = pre->next;
		}
		else
		{
			pre = pre->next;
			p = p->next;
		}
	}
}

/*
8.给定两个单链表，编写算法找出两个链表的公共结点。
WARNING: 需要复习
*/
LinkList FindPublicNode(LinkList l1, LinkList l2) {
	// 统计两个链表长度
	int len1 = 0, len2 = 0;
	for (LinkList p = l1; p != NULL; p = p->next)
		len1++;
	for (LinkList p = l2; p != NULL; p = p->next)
		len2++;

	// 如果有公共结点, 那么后半段是相同的, 先把两个指针指到离结尾同一个长度上
	LinkList p1 = l1, p2 = l2;
	if (len1 > len2) {
		for (int i = 0; i < len1 - len2; i++)
			p1 = p1->next;
	}
	else {
		for (int i = 0; i < len2 - len1; i++)
			p2 = p2->next;
	}
	// 然后判断是否相等
	while (p1 != NULL) {
		if (p1 == p2)
			return p1;
		p1 = p1->next;
		p2 = p2->next;
	}
	return NULL;
}

/*
9.给定一个带表头结点的单链表，设head为头指针，结点结构为(data, next)，data
为整型元素，next为指针，试写出算法:按递增次序输出单链表中各结点的数据元素，
并释放结点所占的存储空间(要求:不允许使用数组作为辅助空间)。
*/
void PrintBySort(LinkList& head) {
	while (head->next != NULL) {
		LinkList pre = head, p = head->next;
		LinkList min_pre = head, min_p = head->next;
		while (p != NULL) {
			if (p->data < min_p->data) { // 更新和保存最小值的结点及其前缀
				min_pre = pre;
				min_p = p;
			}
			pre = pre->next;
			p = p->next; // 更新链表指针
		}
		printf("%d ", min_p->data);
		min_pre->next = min_p->next;
	}
}

/*
10.将一个带头结点的单链表A分解为两个带头结点的单链表A和B，使得A表中含有原表
中序号为奇数的元素,而B表中含有原表中序号为偶数的元素，且保持其相对顺序不变。
*/
void SplitLink(LinkList& A, LinkList& B) {
	LNode odd = { 0, NULL }, even = { 0, NULL };
	LinkList odd_p = &odd, even_p = &even;

	LinkList p = A->next;
	while (p != NULL) {
		if (p->data % 2 == 1) {
			odd_p->next = p;
			odd_p = odd_p->next;
		}
		else
		{
			even_p->next = p;
			even_p = even_p->next;
		}
	}

	A->next = odd.next;
	B->next = even.next;
}

/*
11.设C={a1, b1, a2, b2, …, an, bn}为线性表，采用带头结点的hc单链表存放，设计一个就地
算法，将其拆分为两个线性表，使得A={a1, a2, …, an}，B= {bn, …, b2, b1}。
*/
void SplitLink11(LinkList& hc, LinkList& ha, LinkList& hb) {
	int i = 0;
	LinkList p = hc->next;
	LinkList pa = ha;
	while (p != NULL) {
		if ((i++) % 2 == 0) {
			// A
			pa->next = p;
			pa = pa->next;
			p = p->next;
		}
		else
		{
			// B
			LinkList tmp = p->next; // 暂存p的下一结点
			p->next = hb->next;
			hb->next = p;
			p = tmp;
		}
	}
}

/*
12.在一个递增有序的线性表中，有数值相同的元素存在。若存储方式为单链表，设计算法
去掉数值相同的元素,使表中不再有重复的元素,例如(7,10,10,21,30,42,42,42,51,70)
将变为(7,10,21,30,42,51,70)。
*/
void UniqueLink(LinkList& l) {
	LinkList p = l;
	while (p != NULL && p->next != NULL) {
		if (p->data == p->next->data)
			p->next = p->next->next; // q=p.next; free(q); p.next=p.next.next;
		else
			p = p->next;
	}
}

/*
13.假设有两个按元素值递增次序排列的线性表，均以单链表形式存储。请编写算法将这两
个单链表归并为一个按元素值递减次序排列的单链表，并要求利用原来两个单链表的结点存放归并后的单链表。
*/
void MergeSortedLink(LinkList& l1, LinkList& l2) {
	LNode head = { 0, NULL }; // 暂时使用head来存放归并后的链表
	LinkList p1 = l1, p2 = l2;
	while (p1 != NULL && p2 != NULL) {
		if (p1->data <= p2->data) { //将比较小的结点头插法加入到head链表中
			LinkList next = p1->next; // 暂存后继结点
			p1->next = head.next;
			head.next = p1;
			p1 = next;
		}
		else
		{
			LinkList next = p2->next; // 暂存后继结点
			p2->next = head.next;
			head.next = p2;
			p2 = next;
		}
	}
	while (p1 != NULL) {
		LinkList next = p1->next; // 暂存后继结点
		p1->next = head.next;
		head.next = p1;
		p1 = next;
	}
	while (p2 != NULL) {
		LinkList next = p2->next; // 暂存后继结点
		p2->next = head.next;
		head.next = p2;
		p2 = next;
	}
	// 将l1和l2指向head指向的链表
	l1 = head.next;
	l2 = head.next;
}

/*
14.设A和B是两个单链表（带头结点)，其中元素递增有序。设计一个算法从A和B中的
公共元素产生单链表C，要求不破坏A、B的结点。
*/
void FindPublicLink(LinkList ha, LinkList hb, LinkList& hc) {
	LinkList p1 = ha->next, p2 = hb->next, p3 = hc;
	while (p1 != NULL && p2 != NULL) {
		if (p1->data == p2->data) {
			LinkList newptr = (LinkList)malloc(sizeof(LNode));
			newptr->next = NULL;
			newptr->data = p1->data;

			p3->next = newptr;
			p3 = p3->next;
			p1 = p1->next;
			p2 = p2->next;
		}
		else {
			if (p1->data < p2->data)
				p1 = p1->next;
			else
				p2 = p2->next;
		}
	}
}

/*
15.已知两个链表A和B分别表示两个集合，其元素递增排列。编制函数，求A与B的交
集，并存放于A链表中。
*/
// 跟上一题差不多, 不写了

/*
16.两个整数序列 A=a1, a2, a3, …, am 和 B=b1, b2, b3, …, bn 已经存入两个单链表中，设计一
个算法，判断序列B是否是序列A的连续子序列。
*/
bool CheckSubLink(LinkList A, LinkList B) {
	if (A == NULL || B == NULL)
		return false;

	LinkList pa = A; // A的外层指针, 每一轮对[pa, am]和[b1, bn]作比较
	while (pa != NULL) {
		LinkList pa1 = pa; // A的内层指针
		LinkList pb = B; // B的指针
		while (pa1->data == pb->data) { // 找到[pa, am]中与b1相同的元素, 然后比较后续是否相同
			pa1->next = pa1->next;
			pb->next = pb->next;
			if (pb == NULL) // B遍历到尾部每一个元素都相同, 说明是子序列
				return true;
			if (pa1 == NULL) // A遍历到尾部, 而B没到尾部, 不是子序列
				goto next;
		}
	next:
		pa = pa->next;
	}
	return false;
}

// TODO: 没写循环链表数据结构, 剩下的放课本习题上去写

int main() {
	DeleteXTest();
}
