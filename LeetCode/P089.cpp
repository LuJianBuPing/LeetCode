#include "LeetCode.h"

class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> result = { 0 };
		for (int i = 1; i <= n; ++i)
		{
			int size = result.size();
			int x = 1 << (i - 1);
			for (int j = size - 1; j >= 0; --j)
				result.push_back(x | result[j]);
		}
		return result;
	}
};