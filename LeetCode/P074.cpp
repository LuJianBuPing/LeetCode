#include "LeetCode.h"

class Solution {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int m = matrix.size();
		int n = m == 0 ? 0 : matrix[0].size();
		if (m == 0 || n == 0)
			return false;

		int l = 0, r = m*n - 1;

		while (l <= r)
		{
			int mid = (l + r) / 2;

			int v = getValue(matrix, mid, n);

			if (v == target)
				return true;
			else if (v>target)
				r = mid - 1;
			else if (v<target)
				l = mid + 1;
		}
		return false;
	}

	int getValue(vector<vector<int> > &matrix, int i, int n)
	{
		return matrix[i / n][i%n];
	}
};