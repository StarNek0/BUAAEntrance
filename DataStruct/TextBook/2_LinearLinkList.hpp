typedef int ElemType;

// 链表
typedef struct Node {
	ElemType data;
	struct Node* next; // 有的书也将next命名为link, 这里统一用next
} LinkNode, * LinkList;

void Print(LinkList list);

LinkList CreateListByArray(ElemType A[], int n);

// 双向链表
struct DNode {
	ElemType data;
	struct DNode* left;
	struct DNode* right;
} DLinkNode, * DLinkList;
