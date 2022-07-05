#pragma once
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int M = 1000;

typedef struct node {
	int data;
	struct node* next;
}Node, * LinkNode;