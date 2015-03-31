#include "LeetCode.h"

class Solution {

	int target;
	vector<vector<int>> result;
	vector<int> candidates;
	int* sol;
private:
	void findSol(int n, int sum, int pos)
	{
		if (sum > target) return;
		if (sum == target)
		{
			vector<int> onesol;
			for (int i = 0; i < n; ++i)
				onesol.push_back(sol[i]);
			result.push_back(std::move(onesol));
			return;
		}

		for (int i = pos; i < candidates.size(); ++i)
		{
			if (i>pos && candidates[i] == candidates[i - 1])
				continue;
			int value = candidates[i];
			sol[n] = value;
			findSol(n + 1, sum + value, i+1);
		}
	}
public:
	vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
		sort(candidates.begin(), candidates.end());
		this->candidates = candidates;
		this->target = target;

		sol = new int[candidates.size()];
		findSol(0, 0, 0);
		return std::move(result);
	}
};

//int main()
//{
//	vector<int> tv = { 10, 1, 2, 7, 6, 1, 5 };
//
//	Solution sl;
//	displayVector2(sl.combinationSum2(tv, 8));
//
//	PAUSE;
//}