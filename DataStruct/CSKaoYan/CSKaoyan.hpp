#pragma once
#include<cstdio>
#include<cassert>
#include<iostream>
#include<queue>
#include<stack>

using namespace std;

typedef int ElemType;

// 顺序表
#define MaxSize 50
typedef struct {
	ElemType data[MaxSize];
	int length;
} SqList;
// 单链表
typedef struct LNode {
	ElemType data;
	struct LNode* next;
} LNode, * LinkList;
// 双链表
typedef struct DNode {
	ElemType data;
	struct DNode* prior, * next;
} DNode, * DlinkList;

// 栈
typedef struct {
	ElemType data[MaxSize];
	int top;
} SqStack;
typedef struct listack {
	ElemType data;
	struct listack* next;
} *LiStack;

//队列
typedef struct {
	ElemType data[MaxSize];
	int front, rear;
} SqQueue;
typedef struct linknode {
	ElemType data;
	struct linknode* next;
}linknode;
typedef struct {
	linknode* front, * rear;
}linkqueue;

// 图

// 图的邻接矩阵存储结构定义
#define MaxVertexNum 100	// 顶点数目最大值
typedef char VertexType;	// 顶点数据类型
typedef int EdgeType;		// 边矩阵上权值的数据类型
typedef struct {
	VertexType Vex[MaxVertexNum]; // 顶点表
	EdgeType Edge[MaxVertexNum][MaxVertexNum]; // 邻接矩阵, 边表
	int vexnum;	// 图的顶点数
	int arcnum;	// 图的边数
} MGraph;

// 图的邻接表存储结构定义
typedef struct ArcNode {	// 边
	int adjvex;				// 顶点位置索引
	struct ArcNode* next;	// 下一个边
	//InfoType info;		// 权值
} ArcNode;
typedef struct VNode {	// 顶点
	VertexType data;			// 顶点包含信息
	ArcNode* first;		// 指向第一个边的指针
} VNode, AdjList[MaxVertexNum];
typedef struct {
	AdjList vertices;	// 邻接表
	int vexnum;	// 图的顶点数
	int arcnum;	// 图的边数
} ALGraph;