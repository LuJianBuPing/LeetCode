#include "LeetCode.h"

class Solution {
	vector<vector<int>> result;
	vector<int> sol;
	int n;
	int k;
public:
	vector<vector<int> > combine(int n, int k) {
		this->n = n;
		this->k = k;
		sol = vector<int>(k, 0);

		dfs(0, 1);
		return result;
	}

	void dfs(int i, int pos)
	{
		if (i == k)
		{
			result.push_back(sol);
			return;
		}

		for (int j = pos; j <= n; ++j)
		{
			sol[i] = j;
			dfs(i + 1, j + 1);
		}
	}
};

