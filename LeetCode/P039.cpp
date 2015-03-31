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

		for (int i = pos; i < candidates.size();++i)
		{
			int value = candidates[i];
			sol[n] = value;
			findSol(n + 1, sum + value, i);
		}
	}
public:
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		sort(candidates.begin(), candidates.end());
		this->candidates = candidates;
		this->target = target;

		sol = new int[target/candidates[0]+1];
		findSol(0, 0, 0);
		return std::move(result);
	}
};

//int main()
//{
//	vector<int> tv = { 3, 8, 5 };
//
//	Solution sl;
//	displayVector2(sl.combinationSum(tv, 11));
//
//	PAUSE;
//}