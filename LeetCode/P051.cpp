#include "LeetCode.h"

class Solution {
	int n;
	int answer[32];
	vector<vector<string> > result;
public:
	vector<vector<string> > solveNQueens(int n) {
		this->n = n;
		result.clear();
		solve(0,0,0,0);
		return std::move(result);
	}

	void solve(int row, unsigned col, unsigned diag1, unsigned diag2)
	{
		if (row == n)
		{
			vector<string> onesol;
			for (int i = 0; i < n; ++i)
			{
				string str(n, '.');
				str[answer[i]] = 'Q';
				onesol.push_back(std::move(str));
			}
			result.push_back(std::move(onesol));
			return;
		}

		unsigned colmark = 1, diag1mark = 1 << row, diag2mark = 1 << (n - 1 - row);
		for (int i = 0; i < n; ++i)
		{
			if (!((col&colmark) || (diag1&diag1mark) || (diag2&diag2mark)))
			{
				answer[row] = i;
				solve(row + 1, col|colmark, diag1|diag1mark, diag2|diag2mark);
			}

			colmark <<= 1;
			diag1mark <<= 1;
			diag2mark <<= 1;
		}
	}
};

class Solution2 {
	unsigned col, diag1, diag2;
	int n;
	int answer[32];
	vector<vector<string> > result;
public:
	vector<vector<string> > solveNQueens(int n) {
		col = diag1 = diag2 = 0;
		this->n = n;
		result.clear();
		solve(0);
		return std::move(result);
	}

	void solve(int row)
	{
		if (row == n)
		{
			vector<string> onesol;
			for (int i = 0; i < n; ++i)
			{
				string str(n, '.');
				str[answer[i]] = 'Q';
				onesol.push_back(std::move(str));
			}
			result.push_back(std::move(onesol));
			return;
		}

		unsigned colmark = 1, diag1mark = 1 << row, diag2mark = 1 << (n - 1 - row);
		for (int i = 0; i < n; ++i)
		{
			if (!((col&colmark) || (diag1&diag1mark) || (diag2&diag2mark)))
			{
				answer[row] = i;

				col |= colmark;
				diag1 |= diag1mark;
				diag2 |= diag2mark;

				solve(row + 1);

				col ^= colmark;
				diag1 ^= diag1mark;
				diag2 ^= diag2mark;
			}

			colmark <<= 1;
			diag1mark <<= 1;
			diag2mark <<= 1;
		}
	}
};

//int main()
//{
//	Solution sl;
//
//	displayVector2(sl.solveNQueens(4));
//
//	PAUSE;
//}