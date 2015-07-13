#include "LeetCode.h"

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		vector<vector<int>> f(prices.size() + 1, vector<int>(2, 0));
		f[0][0] = 0;
		f[0][1] = INT_MIN/2;

		for (int i = 1; i <= prices.size(); ++i)
		{
			int p = prices[i-1];
			f[i][0] = max(f[i - 1][0], f[i - 1][1] + p);
			f[i][1] = max(f[i - 1][1], f[i - 1][0] - p);
		}

		return max(f[prices.size()][0], f[prices.size()][1]);
	}
};