#include "8_Graph.hpp"

// <数据结构教程>p215 邻接矩阵存储方式来建立图
void AdjMatrix(int A[][MaxVNum], int n, int e) {
	// 初始化节点
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			A[i][j] = MaxValue;
	int i, j, weight = 1;
	// 输入每条边
	for (int k = 0; k < e; k++) {
		cin >> i >> j; // >> weight;
		A[i][j] = weight;
		A[j][i] = weight;
	}
}

// <数据结构教程>p217 邻接表存储方式来建立图
void AdjList(VLink G[], int n, int e) {
	// 初始化节点
	for (int k = 0; k < n; k++) {
		G[k] = VLink{};
		G[k].vertex = 'A' + k;
		G[k].link = NULL;
	}
	int i, j, weight;
	// 输入每条边
	for (int k = 0; k < e; k++) {
		cin >> i >> j; // >> weight;
		ELink* newedge = (ELink*)malloc(sizeof(ELink));
		newedge->adjvex = j;
		newedge->next = NULL;
		//newedge->weight = weight;
		cout << G[i].vertex << " --> " << G[j].vertex << endl; // debug

		if (G[i].link == NULL)
			G[i].link = newedge;
		else {
			ELink* p = G[i].link;
			while (p->next != NULL)
				p = p->next;
			p->next = newedge;
		}

	}
}

// 打印邻接表
void PrintVer(VLink G[], int n) {
	for (int k = 0; k < n; k++) {
		cout << G[k].vertex << "  -->  ";
		ELink* p = G[k].link;
		while (p != NULL) {
			cout << G[p->adjvex].vertex << " --> ";
			p = p->next;
		}
		cout << "NULL" << endl;
	}
}

// <数据结构教程>p218 邻接表存储方式下删除指定元素
void DelVer(VLink G[], int n, string item) {
	// 找到顶点, 用flag标记它, 并删除其边
	int flag = -1;
	for (int i = 0; i < n; i++)
	{
		if (G[i].vertex == item) {
			flag = i;
			ELink* p = G[i].link, * q = NULL;
			while (p != NULL)
			{
				q = p;
				p = p->next;
				free(q);
			}
		}
	}
	if (flag == -1)
		return;

	// 删除顶点
	for (int i = flag; i < n - 1; i++)
	{
		G[i] = G[i + 1];
	}
	n--;

	// 删除其他顶点和此顶点的边
	for (int i = 0; i < n; i++)
	{
		if (G[i].link == NULL)
			continue;

		ELink* q = NULL;
		if (G[i].link->adjvex == flag) {
			q = G[i].link;
			G[i].link = NULL;
			free(q);
			continue;
		}

		ELink* p = G[i].link;
		while (p!= NULL && p->next != NULL)
		{
			if (p->next->adjvex == flag) {
				q = p->next;
				p->next = p->next->next;
				free(q);
			}
			p = p->next;
		}
	}


	// adjvex都要更新
	for (int i = 0; i < n; i++)
	{
		if (G[i].link == NULL)
			continue;
		ELink* p = G[i].link;
		while (p != NULL) {
			if (p->adjvex > flag) // adjvex==flag的应该已经被删掉了
				p->adjvex--;
			p = p->next;
		}
	}
}
void DelVerTest() {
	/*
	* 以书上8.6有向图为例
	0 1
	0 5
	1 4
	2 1
	2 4
	3 2
	3 4
	4 1
	4 0
	5 1
	5 4
	*/
	VLink G[100];
	AdjList(G, 6, 11);
	PrintVer(G, 6);
	cout << endl;
	/*
	A  -->  B --> F --> NULL
	B  -->  E --> NULL
	C  -->  B --> E --> NULL
	D  -->  C --> E --> NULL
	E  -->  B --> A --> NULL
	F  -->  B --> E --> NULL
	删除后:
	A  -->  B --> F --> NULL
	B  -->  NULL
	C  -->  B --> NULL
	D  -->  C --> NULL
	F  -->  B --> NULL
	*/
	DelVer(G, 6, "E");
	PrintVer(G, 5);
}

// 这一部分样例代码完整度太差, 缺胳膊少腿, 近似于伪代码, 因此略过, 转王道

//int main() {
//	DelVerTest();
//}