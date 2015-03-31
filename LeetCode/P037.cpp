#include "LeetCode.h"

class Solution {
	static const int max_col = 9 * 9 * 4;
	static const int max_row = 81 * 9;
	static const int max_num_nodes = 1 + max_col + max_row * 4;

	int num_nodes;
	int head;
	int L[max_num_nodes], R[max_num_nodes], U[max_num_nodes], D[max_num_nodes], C[max_num_nodes];
	int S[max_col];
	int ans[max_col];
private:
	void makeHead()
	{
		head = max_col;
		C[head] = L[head] = R[head] = U[head] = D[head] = head;
		for (int i = 0; i < max_col;++i)
		{
			insertNode(i, i, head);
			S[i] = 0;
		}
		num_nodes = max_col + 1;
	}

	void insertNode(int n, int hcol, int hrow)
	{
		if (hrow != n)
		{
			R[n] = hrow;
			L[n] = L[hrow];
			L[hrow] = R[L[n]] = n;
		}
		else
			L[n] = R[n] = n;
		
		if (hcol != n)
		{
			D[n] = hcol;
			U[n] = U[hcol];
			U[hcol] = D[U[n]] = n;
		}
		else
			U[n] = D[n] = n;

		C[n] = hcol;
		S[hcol]++;
	}

	void insertSudoku(int r, int c, int v)
	{
		int col1 = r*9+c;
		int col2 = 81 + r * 9 + v - 1;
		int col3 = 162 + c * 9 + v - 1;
		int col4 = 243 + ((r / 3) * 3 + (c / 3)) * 9 + v - 1;

		int hrow = num_nodes;
		insertNode(num_nodes++, col1, hrow);
		insertNode(num_nodes++, col2, hrow);
		insertNode(num_nodes++, col3, hrow);
		insertNode(num_nodes++, col4, hrow);
	}

	void reduce(int c)
	{
		R[L[c]] = R[c];
		L[R[c]] = L[c];

		for (int i = D[c]; i != c; i = D[i])
		{
			for (int j = R[i]; j != i; j = R[j])
			{
				U[D[j]] = U[j];
				D[U[j]] = D[j];
				--S[C[j]];
			}
		}
	}

	void resume(int c)
	{
		for (int i = U[c]; i != c; i = U[i])
		{
			for (int j = L[i]; j != i; j = L[j])
			{
				U[D[j]] = j;
				D[U[j]] = j;
				++S[C[j]];
			}
		}
		R[L[c]] = c;
		L[R[c]] = c;
	}

	bool solve(int depth)
	{
		if (R[head] == head)
		{
			ans[depth] = -1;
			return true;
		}

		int minc = R[head];
		for (int i = R[head]; i != head; i = R[i])
			if (S[i] < S[minc])
				minc = i;

		reduce(minc);
		for (int i = D[minc]; i != minc; i = D[i])
		{
			for (int j = R[i]; j != i; j = R[j])
				reduce(C[j]);

			ans[depth] = i;
			if (solve(depth + 1))
				return true;

			for (int j = L[i]; j != i; j = L[j])
				resume(C[j]);
		}

		resume(minc);
		return false;
	}

public:
	void solveSudoku(vector<vector<char> > &board) {
		makeHead();

		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				if (board[i][j] != '.')
					insertSudoku(i, j, board[i][j] - '0');
				else
				{
					for (int k = 1; k <= 9; ++k)
					{
						insertSudoku(i, j, k);
					}
				}
			}
		}

		solve(0);

		for (int i = 0; ans[i] >= 0; ++i)
		{
			int p = C[ans[i]]<81?C[ans[i]]:0;
			char v;
			for (int j = R[ans[i]]; j != ans[i]; j = R[j])
			{
				if (C[j] < 81)
					p = C[j];
				else
					v = C[j] % 9 + '1';
			}

			board[p / 9][p % 9] = v;
		}
	}
};

static vector<vector<char>> makeBoard(vector<string>& input)
{
	vector<vector<char>> result;

	for (int i = 0; i < input.size(); ++i)
	{
		vector<char> row;
		for (auto ch : input[i])
			row.push_back(ch);
		result.push_back(row);
	}

	return result;
}


//int main()
//{
//	Solution sl;
//	vector<string> input = { 
//		"53..7....", 
//		"6..195...", 
//		".98....6.", 
//		"8...6...3", 
//		"4..8.3..1", 
//		"7...2...6", 
//		".6....28.", 
//		"...419..5", 
//		"....8..79" };
//
//	auto board = makeBoard(input);
//
//	sl.solveSudoku(board);
//
//	displayVector2(board);
//
//	PAUSE;
//}