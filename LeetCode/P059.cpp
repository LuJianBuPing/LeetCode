#include "LeetCode.h"

class Solution {
public:
	vector<vector<int> > generateMatrix(int n) {
		int dr[] = {0,1,0,-1};
		int dc[] = {1,0,-1,0};

		vector<vector<int>> result(n,vector<int>(n,0));

		int row = 0, col = -1 ,dir = 0;
		for (int i = 0; i < n*n; ++i)
		{
			label1:
			int r = row + dr[dir];
			int c = col + dc[dir];

			if (r < 0 || c < 0 || r >= n || c >= n || result[r][c] != 0)
			{
				dir = (dir+1)&3;
				goto label1;
			}
			row = r, col = c;
			result[r][c] = i + 1;
		}
		return std::move(result);
	}
};

//
//int main()
//{
//	Solution sl;
//
//	displayVector2(sl.generateMatrix(4));
//
//	PAUSE;
//}