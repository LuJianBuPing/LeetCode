#include "LeetCode.h"

class Solution {
public:
	int searchInsert(int A[], int n, int target) {
		//return lower_bound(A, A + n, target) - A;
		if (n == 0 || target < A[0])
			return 0;
		if (target > A[n - 1])
			return n;
		int i = 0, j = n - 1;

		while (i < j)
		{
			int mid = (i + j) / 2;
			if (A[mid] >= target)
				j = mid;
			else
				i = mid+1;
		}
		return i;
	}
};

//int main()
//{
//	Solution sl;
//	int A[] = {1,3,5,6};
//	cout << sl.searchInsert(A, 4, 5) << endl;
//	cout << sl.searchInsert(A, 4, 2) << endl;
//	cout << sl.searchInsert(A, 4, 7) << endl;
//	cout << sl.searchInsert(A, 4, 0) << endl;
//	cout << sl.searchInsert(A, 0, 1) << endl;
//
//	PAUSE;
//}