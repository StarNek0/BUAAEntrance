typedef int ElemType;

typedef struct Node {
	ElemType data;
	struct Node* link;
} LinkNode, * LinkList;

void Print(LinkList list);