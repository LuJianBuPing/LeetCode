#include "LeetCode.h"

int dirx[4] = { -1, 0, 1, 0 };
int diry[4] = { 0, -1, 0, 1 };
class Solution {
	int m;
	int n;
	string word;
public:
	bool exist(vector<vector<char> > &board, string word) {
		m = board.size();
		n = m == 0 ? 0 : board[0].size();
		if (m == 0 || n == 0) return false;
		if (word.length() == 0) return true;
		this->word = word;

		vector<vector<bool>> used(board.size(),vector<bool>(board[0].size()));
		
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (board[i][j] == word[0])
				{
					used[i][j] = true;
					if (dfs_find(board, used, i, j, 1))
						return true;
					used[i][j] = false;
				}
			}
		}

		return false;
	}

	bool dfs_find(vector<vector<char> > &board, vector<vector<bool>>& used,int x, int y, int i)
	{
		if (i == word.length())
			return true;

		for (int d = 0; d < 4; ++d)
		{
			int xx = x + dirx[d];
			int yy = y + diry[d];

			if (xx < 0 || yy < 0 || xx >= m || yy >= n) continue;

			if (board[xx][yy] == word[i] && !used[xx][yy])
			{
				used[xx][yy] = true;
				if (dfs_find(board, used, xx, yy, i + 1))
					return true;
				used[xx][yy] = false;
			}
		}
		return false;
	}
};

