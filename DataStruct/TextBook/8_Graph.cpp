#include "8_Graph.hpp"

// <数据结构教程>p215 邻接矩阵存储方式来建立图
void AdjMatrix(int A[][MaxVNum], int n, int e) {
	// 初始化节点
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			A[i][j] = MaxValue;
	int i, j, weight;
	// 输入每条边
	for (int k = 0; k < e; k++) {
		cin >> i >> j >> weight;
		A[i][j] = weight;
		A[j][i] = weight;
	}
}

// <数据结构教程>p217 邻接矩阵存储方式来建立图
void AdjList(VLink G[], int n, int e) {
	// 初始化节点
	for (int k = 0; k < n; k++) {
		G[k].vertex = 'a' + k;
		G[k].link = NULL;
	}
	int i, j, weight;
	// 输入每条边
	for (int k = 0; k < e; k++) {
		cin >> i >> j >> weight;
		ELink* newedge = (ELink*)malloc(sizeof(ELink));
		newedge->adjvex = j;
		newedge->next = NULL;
		newedge->weight = weight;

		if (G[k].link == NULL)
			G[k].link = newedge;
		else {
			ELink* p = G[k].link;
			while (p->next != NULL)
				p = p->next;
			p->next = newedge;
		}

	}
}

int main() {

}