#include "LeetCode.h"

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		vector<int> f(n, 0);
		for (int i = 0; i<n; ++i)
		{
			f[i] = triangle[i][i] + (i == 0 ? 0 : f[i - 1]);
			for (int j = i - 1; j>0; --j)
				f[j] = min(f[j] + triangle[i][j], f[j - 1] + triangle[i][j]);
			f[0] += (i == 0 ? 0 : triangle[i][0]);
		}

		int result = f[0];
		for (int i = 1; i<n; ++i)
			result = min(result, f[i]);
		return result;
	}
};