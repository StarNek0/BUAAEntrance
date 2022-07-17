#pragma once
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

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

// 二叉树
typedef struct btnode {
	datatype data;
	struct btnode* lchild, * rchild;
}BTNode, * BTree;

// 线索二叉树
typedef struct tbtnode {
	datatype data;
	struct tbtnode* lchild, * rchild;
	int lbit, rbit;
}TBTNode, * TBTree;

