#pragma once
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MaxTreeD = 100;
typedef char datatype;

// 定长多重链表
typedef struct dnode {
	int data;
	struct dnode* child[MaxTreeD];
}DTree;


// 不定长多重链表
typedef struct nnode {
	int data;
	int degree;
	struct nnode* child[MaxTreeD];
}NTree;


// 三重链表
typedef struct tnode {
	int data;
	struct tnode* child, * parent, * brother;
}TTree;

typedef struct bnode {
	datatype data;
	struct bnode* lchild, * rchild;
}BinNode, * BinTree;

