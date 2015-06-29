#include "LeetCode.h"

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> result;

		if (numRows >= 1)
			result.push_back(vector<int>(1, 1));

		for (int i = 2; i <= numRows; ++i)
		{
			auto& last_row = result.back();
			vector<int> row;
			row.push_back(1);

			for (int j = 0; j<last_row.size() - 1; ++j)
				row.push_back(last_row[j] + last_row[j + 1]);

			row.push_back(1);
			result.push_back(row);
		}

		return result;
	}
};