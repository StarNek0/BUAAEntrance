#pragma once
#include<cstdio>
#include<cassert>
#include<iostream>
#include<queue>
#include<stack>

using namespace std;

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