#include "LeetCode.h"

class Solution {
public:
	int removeDuplicates(int A[], int n) {
		int i = 0;
		for (int j=1; j < n;++j)
			if (A[j] != A[i])
				A[++i] = A[j];
		return min(i+1,n);
	}
};

//int main()
//{
//	int A[] = { 1, 2, 2, 2, 2, 2,4 };
//
//	Solution sl;
//	int n = sl.removeDuplicates(A,7);
//	displayArray(A,n);
//
//	PAUSE;
//}