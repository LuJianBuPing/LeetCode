#include "LeetCode.h"

class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		for (int i = 0; i < n; ++i)
			if (A[i] == elem)
				A[i--] = A[--n];
		return n;
	}
};

//int main()
//{
//	int A[] = { 1, 2, 3,3 };
//
//	Solution sl;
//
//	int n = sl.removeElement(A, 1, 1);
//	
//	displayArray(A, n);
//
//	PAUSE;
//}