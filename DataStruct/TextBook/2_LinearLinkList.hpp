typedef int ElemType;

// 链表
typedef struct Node {
	ElemType data;
	struct Node* next; // 有的书也将next命名为link, 这里统一用next
} LinkNode, * LinkList;

void Print(LinkList list);

// 创建单向链表
LinkList CreateListByArray(ElemType A[], int n);

// 创建循环链表
LinkList CreateListByArray(ElemType A[], int n, bool loop);

// 双向链表
typedef struct DNode {
	ElemType data;
	struct DNode* left;
	struct DNode* right;
} DLinkNode, * DLinkList;

void Print(DLinkList list);

// 创建双向链表
DLinkList CreateDListByArray(ElemType A[], int n);

// 创建双向循环链表
DLinkList CreateDListByArray(ElemType A[], int n, bool loop, bool head);

// 多项式链表
typedef struct PNode {
	int coef; // 系数
	int exp; // 指数
	struct PNode* next;
} PLinkNode, *PLinkList;