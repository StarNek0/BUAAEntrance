#include "CSKaoyan.hpp"

// 王道也同样是伪代码, 唉

// <数据结构教程>p215 邻接矩阵存储方式来建立图
MGraph NewMGraph(int n, int e) {
    MGraph G = {};
    G.vexnum = n;
    G.arcnum = e;
    // 初始化节点
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			G.Vex[i][j] = INT32_MAX;
    int i, j, weight = 1;
    // 输入每条边
    for (int k = 0; k < e; k++) {
        cin >> i >> j; // >> weight;
        G.Edge[i][j] = weight;
        G.Edge[j][i] = weight;
    }
    return G;
}

// <数据结构教程>p217 邻接表存储方式来建立图
ALGraph NewALGraph(int n, int e) {
    ALGraph G = {};
    G.vexnum = n;
    G.arcnum = e;
    // 初始化节点
    for (int k = 0; k < n; k++) {
        //		G.vertices[k] = ArcNode{};
        G.vertices[k].data = 'A' + k;
        G.vertices[k].first = NULL;
    }
    int i, j, weight = 0;
    // 输入每条边
    for (int k = 0; k < e; k++) {
        cin >> i >> j;
        ArcNode* newedge = (ArcNode*)malloc(sizeof(ArcNode));
        newedge->adjvex = j;
        newedge->next = NULL;
        cout << G.vertices[i].data << " --> " << G.vertices[j].data << endl; // debug

        if (G.vertices[i].first == NULL)
            G.vertices[i].first = newedge;
        else {
            ArcNode* p = G.vertices[i].first;
            while (p->next != NULL)
                p = p->next;
            p->next = newedge;
        }

    }
    return G;
}

// 打印邻接表
void PrintGraph(ALGraph G) {
    for (int k = 0; k < G.vexnum; k++) {
        cout << G.vertices[k].data << "  -->  ";
        ArcNode* p = G.vertices[k].first;
        while (p != NULL) {
            cout << G.vertices[p->adjvex].data << " --> ";
            p = p->next;
        }
        cout << "NULL" << endl << endl;
    }
}

// 图的邻接表存储结构下的广搜
void BFS(ALGraph G, int v, bool visited[], queue<int> &q) {
    cout << G.vertices[v].data << " ";
    visited[v] = true;
    q.push(v);
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (ArcNode *p = G.vertices[v].first; p != NULL; p = p->next)
            if (!visited[p->adjvex]) {
                cout << G.vertices[p->adjvex].data << " ";
                visited[p->adjvex] = true;
                q.push(p->adjvex);
            }
    }
}
void BFSTraverse(ALGraph G, int v) {
    queue<int> q;
    bool visited[MaxVertexNum] = {};
    for (int i = 0; i < G.vexnum; i++)
        visited[i] = false;

    for (int i = 0; i < G.vexnum; i++)
        if (!visited[i]) {
            BFS(G, i, visited, q);
            cout << "|"; // 代表一条路径结束
        }
}

// 图的邻接矩阵存储结构下的广搜
void BFS(MGraph G, int v, bool visited[], queue<int> &q) {
    cout << G.Vex[v] << " ";
    visited[v] = true;
    q.push(v);
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (int i = 0; i < G.vexnum; i++) {
            // v: 当前顶点 i: 目标顶点
            if (G.Edge[v][i] == true)
                if (!visited[i]) {
                    cout << G.Vex[i] << " ";
                    visited[i] = true;
                    q.push(i);
                }
        }
    }
}
void BFSTraverse(MGraph G, int v) {
    queue<int> q;
    bool visited[MaxVertexNum] = {};
    for (int i = 0; i < G.vexnum; i++)
        visited[i] = false;

    for (int i = 0; i < G.vexnum; i++)
        if (!visited[i])
            BFS(G, i, visited, q);
}

void BFSTraverseTest() {
    /*
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
    ALGraph G = NewALGraph(6, 11);
    PrintGraph(G);
    BFSTraverse(G, 0);
}

int main() {
    BFSTraverseTest();
}