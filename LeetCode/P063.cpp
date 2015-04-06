#include "LeetCode.h"

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		int m = obstacleGrid.size();
		int n = m == 0 ? 0 : obstacleGrid[0].size();

		if (m != 0 && n != 0 && obstacleGrid[0][0] != 1)
			obstacleGrid[0][0] = -1;
		else
			return 0;


		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (obstacleGrid[i][j] == 1 || (i + j == 0))
					continue;

				obstacleGrid[i][j] = getValue(obstacleGrid, i - 1,j) + getValue(obstacleGrid, i, j - 1);
			}
		}

		return obstacleGrid[m-1][n-1] == 1 ? 0 : -obstacleGrid[m-1][n-1];
	}

	int getValue(vector<vector<int> > &obstacleGrid, int m, int n)
	{
		return (m < 0 || n < 0 || obstacleGrid[m][n] > 0) ? 0 : obstacleGrid[m][n];
	}
};

//int main()
//{
//	Solution sl;
//
//	vector<vector<int>> gird = { {0,0,0}, {0,0,0}, {0,0,1} };
//
//	cout << sl.uniquePathsWithObstacles(gird) <<endl;
//
//
//	PAUSE;
//}