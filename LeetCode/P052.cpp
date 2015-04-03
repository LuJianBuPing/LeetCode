#include "LeetCode.h"

class Solution {
	int n;
	int count;
public:
	int totalNQueens(int n) {
		this->n = n;
		this->count = 0;

		solve(0, 0, 0, 0);
		return count;
	}

	void solve(int row, unsigned col, unsigned diag1, unsigned diag2)
	{
		if (row == n)
		{
			++count;
			return;
		}

		unsigned colmark = 1, diag1mark = 1 << row, diag2mark = 1 << (n - 1 - row);
		for (int i = 0; i < n; ++i)
		{
			if (!((col&colmark) || (diag1&diag1mark) || (diag2&diag2mark)))
				solve(row + 1, col | colmark, diag1 | diag1mark, diag2 | diag2mark);


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
//	cout << sl.totalNQueens(4) << endl;
//
//	PAUSE;
//}