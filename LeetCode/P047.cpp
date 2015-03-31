#include "LeetCode.h"

class Solution {
public:
	vector<vector<int> > permuteUnique(vector<int> &num) {
		vector<vector<int>> result;
		sort(num.begin(), num.end());

		result.push_back(num);
		while (next_permutation(num.begin(), num.end()))
		{
			result.push_back(num);
		}
		return result;
	}
};

//int main()
//{
//	Solution sl;
//
//	displayVector2(sl.permuteUnique(vector<int>({ 1, 2, 3 })));
//
//	cout << endl;
//
//	displayVector2(sl.permuteUnique(vector<int>({ 1, 1, 2 })));
//
//	PAUSE;
//}