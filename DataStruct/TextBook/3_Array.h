#include<cstdio>
#include<cassert>
#include<iostream>
using namespace std;


typedef int ElemType;

#define MaxN 100

ElemType LTA[MaxN];


void Print(ElemType A[][MaxN], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
}