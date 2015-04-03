#include "LeetCode.h"

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		int dr[] = { 0, 1, 0, -1 };
		int dc[] = { 1, 0, -1, 0 };

		vector<int> result;

		int m = matrix.size();
		if (m == 0) return result;
		int n = matrix[0].size();
		if (n == 0) return result;

		vector<vector<bool>> mark;

		for (int i = 0; i < m; ++i)
			mark.push_back(vector<bool>(n, false));

		int col = -1, row = 0,dir = 0,c,r;
		for (int i = 0; i < m*n; ++i)
		{
			label1:
			c = col + dc[dir];
			r = row + dr[dir];

			if (c < 0 || r < 0 || c >= n || r >= m || mark[r][c])
			{
				dir = (dir + 1) & 3;
				goto label1;
			}

			result.push_back(matrix[r][c]);
			mark[r][c] = true;
			col = c;
			row = r;
		}
		return std::move(result);
	}
};

//int main()
//{
//
//	vector<vector<int>> m = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
//	vector<vector<int>> n = { {2,3} };
//	Solution sl;
//
//	displayVector(sl.spiralOrder(n));
//
//
//	PAUSE;
//}