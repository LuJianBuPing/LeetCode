#include "LeetCode.h"

class Solution {
public:
	bool search(int A[], int n, int target) {
		int i = 0, j = n - 1;

		if (A[j] == target)
			return true;

		while (j > 0 && A[0] == A[j])
		{
			--j;
			--n;
		}

		while (i + 1 < j)
		{
			int m = (i + j) / 2;

			if (A[m] >= A[i])
				i = m;
			if (A[m] <= A[j])
				j = m;
		}

		//cout << i << "," << j << endl;

		int k = lower_bound(A, A + i + 1, target) - A;
		if (k <= i && A[k] == target) return true;
		k = lower_bound(A + j, A + n, target) - A;
		if (k < n && A[k] == target) return true;
		return false;
	}
};

//int main()
//{
//	Solution sl;
//	int A[] = {1,2,1};
//	
//	cout << sl.search(A,3,2) << endl;
//
//	PAUSE;
//}