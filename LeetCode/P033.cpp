#include "LeetCode.h"

class Solution {
public:
	int search(int A[], int n, int target) {
		int i = 0, j = n - 1;

		while (i + 1 < j)
		{
			int m = (i + j) / 2;

			if (A[m] > A[i])
				i = m;
			if (A[m] < A[j])
				j = m;
		}

		//cout << i << "," << j << endl;

		int k = lower_bound(A, A + i + 1, target) - A;
		if (k <= i && A[k] == target) return k;
		k = lower_bound(A + j, A + n, target) - A;
		if (k < n && A[k] == target) return k;
		return -1;
	}
};

//int main()
//{
//	Solution sl;
//	int A[] = { 4 ,5 ,6 ,7 ,0 ,1 ,2 };
//	cout << sl.search(A, 7, 3) << endl;
//	cout << sl.search(A, 7, 0) << endl;
//	cout << sl.search(A, 7, 7) << endl;
//	cout << sl.search(A, 7, 4) << endl;
//	cout << sl.search(A, 7, 2) << endl;
//
//	cout << sl.search(A, 1, 0) << endl;
//
//	cout << sl.search(A, 2, 5) << endl;
//	PAUSE;
//}