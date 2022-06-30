#pragma once
#include <cstdio>
#include <iostream>

using namespace std;

typedef int ElemType;
const int M = 1000;

// 栈的链式存储
typedef struct node {
	ElemType data;
	struct node* next;
}Node, *LinkNode;