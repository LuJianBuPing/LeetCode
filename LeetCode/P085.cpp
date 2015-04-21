#include "LeetCode.h"

class Solution {
public:
	int maximalRectangle(vector<vector<char> > &matrix) {
		int m = matrix.size();
		int n = m == 0 ? 0 : matrix[0].size();

		if (m == 0 || n == 0) return 0;

		vector<vector<int>> mat(m, vector<int>(n, 0));

		for (int j = 0; j < n; ++j)
			mat[0][j] = matrix[0][j] - '0';

		for (int i = 1; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (matrix[i][j] == '0')
					mat[i][j] = 0;
				else
					mat[i][j] = mat[i - 1][j] + 1;
			}
		}

		int result = 0;

		for (int i = 0; i < m; ++i)
		{
			result = max(result, largestRectangleArea(mat[i]));
		}
		return result;
	}

	int largestRectangleArea(vector<int>& height) {
		stack<pair<int, int>> stk;
		int result = 0;

		height.push_back(0);
		stk.push(make_pair(-1, -1));

		for (int i = 0; i < height.size(); ++i)
		{
			while (stk.top().second >= height[i])
			{
				int h = stk.top().second;
				stk.pop();
				result = max(result, h*(i - stk.top().first - 1));
			}
			stk.push(make_pair(i, height[i]));
		}

		return result;
	}
};

//int main()
//{
//
//	PAUSE;
//}