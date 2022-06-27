#include<cstdio>
#include<cassert>
#include<iostream>
#include<vector>
using namespace std;


typedef int ElemType;

#define MaxN 100

// 打印矩阵
void Print(ElemType A[][MaxN], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}
void Print(vector<vector<ElemType>> A, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}

// 打印压缩矩阵
void PrintCompress(ElemType A[][3], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
}

// 解压缩矩阵
vector<vector<ElemType>> Decompress(int A[][3], int na){
	int m = A[0][0];
	int n = A[0][1];
	vector<vector<ElemType>>B(m);
	for (int i = 0; i < m; i++)
		B[i].resize(n, 0);

	for (int i = 1; i < na; i++) {
		int x = A[i][0]-1;
		int y = A[i][1]-1;
		int v = A[i][2];
		if (x < 0 || y < 0)
			continue;
		B[x][y] = v;
	}
	return B;
}