#/*
	教材 第3章 数组
*/
#include "3_Array.hpp"

// <数据结构教程>p67 下三角矩阵的压缩存储
ElemType* Store(ElemType A[][MaxN], int n) {
	ElemType LTA[MaxN];

	int k = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			LTA[k++] = A[i][j];
	return LTA;
}

// 矩阵的三元组表示法(压缩矩阵)
// [[行数 列数 非零总数] [x1 y1 v1], [x2 y2 v2], ...] , xy为矩阵下标, v是值

// <数据结构教程>p68 稀疏矩阵的转置
void Trans(ElemType TA[][3], ElemType TB[][3]) {
	int k = 1;
	TB[0][0] = TA[0][1];
	TB[0][1] = TA[0][0];
	TB[0][2] = TA[0][2];
	if (TA[0][2] > 0)
		for (int j = 1; j <= TA[0][1]; j++)
			for (int i = 1; i <= TA[0][2]; i++)
				if (TA[i][1] == j) { // 遍历TA的每组的第二个值, 看是否等于j, (j是TB每组的第一个值)
					TB[k][0] = TA[i][1];
					TB[k][1] = TA[i][0];
					TB[k][2] = TA[i][2];
					k++;
				}
}
void TransTest() {
	ElemType TA[][3] = {
		{6,6,8},
		{1,1,15},
		{1,4,22},
		{1,6,-15},
		{2,2,11},
		{2,3,3},
		{3,4,-6},
		{5,1,91},
		{6,3,28},
	};
	PrintCompress(TA);
	cout << endl;
	Print(Decompress(TA), TA[0][0], TA[0][1]);
	cout << endl;

	ElemType TB[9][3] = {};
	Trans(TA, TB);

	cout << endl;
	PrintCompress(TB);
	cout << endl;
	Print(Decompress(TB), TB[0][0], TB[0][1]);
}
// <数据结构教程>p70 稀疏矩阵的相加
void MatrixAdd(int A[][3], int B[][3], int C[][3]) {
	int ia = 1, ib = 1, ic = 1;
	while (ia <= A[0][2] && ib <= B[0][2]) {
		int xa = A[ia][0], ya = A[ia][1], va = A[ia][2];
		int xb = B[ib][0], yb = B[ib][1], vb = B[ib][2];
		int sum = va + vb;

		if (xa == xb)
			if (ya == yb) {
				if (sum != 0) {
					C[ic][0] = xa;
					C[ic][1] = ya;
					C[ic][2] = sum;
					ic++;
				}
				ia++;
				ib++;
			}
			else if (ya < yb) {
					C[ic][0] = xa;
					C[ic][1] = ya;
					C[ic][2] = va;
					ia++;
					ic++;
			}
			else
			{
				C[ic][0] = xb;
				C[ic][1] = yb;
				C[ic][2] = vb;
				ib++;
				ic++;
			}
			
		else if (xa < xb) {
			C[ic][0] = xa;
			C[ic][1] = ya;
			C[ic][2] = va;
			ia++;
			ic++;
		}
		else
		{
			C[ic][0] = xb;
			C[ic][1] = yb;
			C[ic][2] = vb;
			ib++;
			ic++;
		}
	}
	while (ia <= A[0][2]) {
		C[ic][0] = A[ia][0];
		C[ic][1] = A[ia][1];
		C[ic][2] = A[ia][2];
		ia++;
		ic++;
	}
	while (ib <= B[0][2]) {
		C[ic][0] = B[ib][0];
		C[ic][1] = B[ib][1];
		C[ic][2] = B[ib][2];
		ib++;
		ic++;
	}

	C[0][0] = A[0][0];
	C[0][1] = A[0][1];
	C[0][2] = ic - 1;
}
void MatrixAddTest() {
	ElemType TA[][3] = {
	{6,6,8},
	{1,2,15},
	{1,4,22},
	{1,6,-15},
	{2,2,11},
	{2,3,3},
	{3,4,-6},
	{5,1,91},
	{6,3,28},
	};
	ElemType TB[][3] = {
	{6,6,8},
	{1,1,15},
	{1,4,-22},
	{1,6,-15},
	{2,3,11},
	{2,3,3},
	{3,1,-6},
	{3,1,91},
	{6,5,28},
	};
	ElemType TC[MaxN][3];

	MatrixAdd(TA, TB, TC);

	PrintCompress(TA);
	cout << endl;
	PrintCompress(TB);
	cout << endl;
	PrintCompress(TC);
	cout << endl;

	Print(Decompress(TA), TA[0][0], TA[0][1]);
	cout << endl;
	Print(Decompress(TB), TB[0][0], TB[0][1]);
	cout << endl;
	Print(Decompress(TC), TC[0][0], TC[0][1]);
	cout << endl;
}

int main() {
	MatrixAddTest();
}