#include "LeetCode.h"

class Solution {
public:
	void rotate(vector<vector<int> > &matrix) {
		int n = matrix.size();

		for (int x = 0; x < n / 2; ++x)
		{
			for (int y = x; y < n - 1 - x; ++y)
			{
				int t = matrix[x][y];
				int n_x = n - 1 - x, n_y = n - 1 - y;
				matrix[x][y] = matrix[n_y][x];
				matrix[n_y][x] = matrix[n_x][n_y];
				matrix[n_x][n_y] = matrix[y][n_x];
				matrix[y][n_x] = t;
			}
		}
	}
};

//int main()
//{
//
//	vector<vector<int>> matrix = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
//	Solution sl;
//
//	displayVector2(matrix);
//
//	sl.rotate(matrix);
//
//	cout << endl;
//
//	displayVector2(matrix);
//
//
//	PAUSE;
//}