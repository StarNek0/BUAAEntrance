#/*
	教材 第3章 数组
*/
#include "3_Array.h"

// <数据结构教程>p67
void Store(ElemType A[][MaxN], int n) {
	int k = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			LTA[k++] = A[i][j];
}

// <数据结构教程>p68
void Trans(ElemType TA[][3], ElemType TB[][3]) {
	int k = 1;
	TB[0][0] = TA[0][1];
	TB[0][1] = TA[0][0];
	TB[0][2] = TA[0][2];
	if (TA[0][2]>0)
		for(int j=1;j<=TA[0][1];j++)
			for(int i =1;i<=TA[0][2];i++)
				if (TA[i][1] == j) {
					TB[k][0] = TA[i][1];
					TB[k][1] = TA[i][0];
					TB[k][2] = TA[i][2];
					k++;
				}
}

int main() {

}