#include "LeetCode.h"

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		vector<vector<int>> f(2, vector<int>(5,INT_MIN/2));
		int cur = 0;
		f[cur][0] = 0;
		f[1 - cur][0] = 0;

		for (int i = 0; i < prices.size(); ++i)
		{
			int p = prices[i];
			cur = 1 - cur;

			for (int j = 1; j < 5; ++j)
			{
				if (j % 2 == 1)
					f[cur][j] = max(f[1 - cur][j], f[1 - cur][j - 1] - p);
				else
					f[cur][j] = max(f[1 - cur][j], f[1 - cur][j - 1] + p);
			}
		}

		int result = 0;

		for (int i = 0; i < 5; ++i)
			result = max(result, f[cur][i]);
		return result;
	}
};