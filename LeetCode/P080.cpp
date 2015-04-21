#include "LeetCode.h"

class Solution {
public:
	int removeDuplicates(int A[], int n) {
		int i = 1;
		for (int j = 2; j < n; ++j)
			if (A[j] != A[i-1])
				A[++i] = A[j];
		return min(i + 1, n);
	}
};

//int main()
//{
//	Solution sl;
//	int A[] = {1,1,1,1,2,2,3};
//	int n = sl.removeDuplicates(A, 6);
//	displayArray(A,n);
//
//	PAUSE;
//}