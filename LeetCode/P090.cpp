#include "LeetCode.h"


class Solution {
	vector<vector<int>> result;
	vector<int> S;
public:
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
		
		vector<int> curset;
		sort(S.begin(), S.end());
		this->S = S;
		findSubsets(curset, -1, 0);

		/*
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

		sort(result.begin(), result.end());
		result.erase(unique(result.begin(), result.end()),result.end());
		*/
		return std::move(result);
	}

	void findSubsets(vector<int>& curset, int lastpos, int n)
	{
		result.push_back(curset);
		if (n == S.size())
			return;

		for (int i = lastpos + 1; i < S.size(); ++i)
		{
			if (i>lastpos+1 && S[i] == S[i - 1]) continue;
			curset.push_back(S[i]);
			findSubsets(curset, i, n + 1);
			curset.pop_back();
		}
	}
};


//int main()
//{
//	Solution sl;
//	
//	displayVector2(sl.subsetsWithDup(vector<int>({1,1})));
//
//	PAUSE;
//}