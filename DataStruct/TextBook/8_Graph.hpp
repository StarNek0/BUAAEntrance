#pragma once
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MaxValue = INT32_MAX;
const int MaxVNum = 100;

/*
顶点数组列 | 边列
顶点0  -->  边0 --> 边1 --> 边2 --> 边n
顶点1  -->  边0 --> 边1 --> 边2 --> 边n
顶点2  -->  边0 --> 边1 --> 边2 --> 边n
顶点3  -->  边0 --> 边1 --> 边2 --> 边n
...
顶点n  -->  边0 --> 边1 --> 边2 --> 边n
*/

// 边
typedef struct edge {
	int adjvex; // 指向的那个节点在数组中的位置
	int weight; // 权重
	struct edge* next;  // 下一个边
}ELink;

// 顶点
typedef struct ver {
	string vertex; // 顶点数据
	ELink* link; // 指向第一条边
}VLink;