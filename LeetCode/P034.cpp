#include "LeetCode.h"

class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {
		int k = lower_bound(A, A + n, target) - A;
		if (k < n&&A[k] != target || k >= n)
			return vector<int>({-1,-1});

		int l = upper_bound(A, A + n, target) - A;
		return vector<int>({k,l-1});
	}
};

//int main()
//{
//	Solution sl;
//	int A[] = { 5, 6, 7, 8, 8, 10 };
//
//	displayVector(sl.searchRange(A, 6, 8));
//	displayVector(sl.searchRange(A, 6, 10));
//	displayVector(sl.searchRange(A, 6, 5));
//	PAUSE;
//}