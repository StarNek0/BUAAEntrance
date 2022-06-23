typedef int ElemType;

typedef struct Node {
	ElemType data;
	struct Node* next; // 有的书也将next命名为link, 这里统一用next
} LinkNode, * LinkList;

void Print(LinkList list);
LinkList CreateListByArray(ElemType A[], int n);
