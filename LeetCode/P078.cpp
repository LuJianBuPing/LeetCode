#include "LeetCode.h"


class Solution {
public:
	vector<vector<int> > subsets(vector<int> &S) {
		vector<vector<int>> result;

		sort(S.begin(), S.end());
		S.erase(unique(S.begin(), S.end()), S.end());

		int n = S.size();
		int N = 1 << n;

		for (int i = 0; i < N; ++i)
		{
			int k = i;
			vector<int> sol;
			for (int j = 0; j < n; ++j)
			{
				if (k & 1) 
					sol.push_back(S[j]);
				k >>= 1;
			}
			result.push_back(std::move(sol));
		}
		return std::move(result);
	}
};


