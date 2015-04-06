#include "LeetCode.h"

class Solution {
	long long A(int m, int n)
	{
		long long result = 1;
		for (int i = 0; i < n; ++i)
			result *= (m-i);
		return result;
	}

public:
	int uniquePaths(int m, int n) {
		--m; --n;
		if (m < n) swap(m, n);
		return A(m + n, n)/A(n,n);
	}
};

//int main()
//{
//	Solution sl;
//	cout << sl.uniquePaths(1, 3) << endl;
//
//	PAUSE;
//
//}