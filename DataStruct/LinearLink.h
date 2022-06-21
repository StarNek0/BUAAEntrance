typedef int Elemtype;

typedef struct Node {
	Elemtype data;
	struct Node* link;
} LNode, * LinkList;
