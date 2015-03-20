#include "LeetCode.h"

class Solution {
	bool used[10];
public:
	bool isValidSudoku(vector<vector<char>> &board) {
		for (int i = 0; i < 9; ++i)
		{
			bool vc = isValidColumn(board, i);
			bool vr = isValidRow(board, i);
			bool vg = isValidGird(board, i);

			if (!(vc&&vr&&vg))
				return false;
		}
		return true;
	}

	bool isValidColumn(vector<vector<char>> &board, int col){
		memset(used, 0, sizeof(used));
		for (int i = 0; i < 9; ++i)
			if (!validate(board, i, col))
				return false;
		return true;
	}

	bool isValidRow(vector<vector<char>> &board, int row){
		memset(used, 0, sizeof(used));
		for (int i = 0; i < 9; ++i)
			if (!validate(board, row, i))
				return false;
		return true;
	}

	bool isValidGird(vector<vector<char>> &board, int gird){
		memset(used, 0, sizeof(used));
		int x = (gird / 3) * 3, y = (gird % 3) * 3;
		
		for (int i = x; i < x + 3; ++i)
			for (int j = y; j < y + 3; ++j)
				if (!validate(board, i, j))
					return false;
		return true;
	}

	bool validate(vector<vector<char>> &board, int i, int j)
	{
		char ch = board[i][j];
		if (ch != '.')
		{
			if (used[ch - '0'])
				return false;
			else
				used[ch - '0'] = true;
		}
		return true;
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
//	vector<string> input = { ".87654321", "2........", "3........", "4........", "5........", "6........", "7........", "8........", "9........" };
//
//	auto board = makeBoard(input);
//	displayVector2(board);
//
//	Solution sl;
//	cout << sl.isValidSudoku(board) <<endl;
//
//	PAUSE;
//}