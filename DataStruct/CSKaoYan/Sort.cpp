#include "CSKaoyan.hpp"

// 直接插入排序
void InsertSort(int A[], int n) {
	int j;
	int a0;
	for (int i = 1; i < n; i++)
		if (A[i] < A[i - 1]) {
			a0 = A[i];
			for (j = i - 1; a0 < A[j]; j--) // *
				A[j + 1] = A[j];
			A[j + 1] = a0;
		}
}

// 折半插入排序
void InsertSortMid(int A[], int n) {
	int j, left, mid, right, a0;
	for (int i = 1; i < n; i++) {
		if (A[i] < A[i - 1]) {
			a0 = A[i];

			left = 1;
			right = i - 1;
			while (left <= right) { // *
				mid = (left + right) / 2;
				if (A[mid] > a0)
					right = mid - 1;
				else
					left = mid + 1;
			}

			for (j = i - 1; a0 < A[j]; j--)
				A[j + 1] = A[j];
			A[j + 1] = a0;
		}
	}
}

// TODO: 希尔排序
void ShellSort(int A[], int n){}

// 冒泡排序
void BubbleSort(int A[], int n) {
	for (int i = 0; i < n; i++)
	{
		bool is_sorted = true;
		for (int j = n-1; j > i; j--)
		{
			if (A[j - 1] > A[j]) {
				int tmp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = tmp;
				is_sorted = false;
			}
		}
		if (is_sorted)
			return;
	}
}

// 快速排序
void QuickSort(int A[], int low, int high){}
int Partition(int A[], int low, int high);

int main() {
	int A[] = { 5, 4, 1, 3, 2 };
	BubbleSort(A, 5);

	for (int v: A)
		cout << v << " ";
	cout << endl;
}