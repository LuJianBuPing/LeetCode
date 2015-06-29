#include "LeetCode.h"

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> result(rowIndex + 1, 0);
		result[0] = 1;

		for (int k = 0; k<rowIndex; ++k)
		{
			int pre = 0;
			for (int i = 0; i <= rowIndex; ++i)
			{
				int v = result[i] + pre;
				pre = result[i];
				result[i] = v;
			}
		}

		return result;
	}
};