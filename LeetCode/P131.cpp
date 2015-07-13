#include "LeetCode.h"

class Solution {
	vector<vector<bool>> f;
	vector<vector<string>> result;
	vector<int> sol;
	string s;
public:
	vector<vector<string>> partition(string s) {
		this->s = s;
		find_palindrome(s);
		sol.push_back(0);
		dfs(0);
		return result;
	}

	void dfs(int i)
	{
		if (i == s.size())
		{
			vector<string> sol2;
			for (int i = 1; i < sol.size(); ++i)
			{
				int x = sol[i - 1], y = sol[i];
				sol2.push_back(s.substr(x, y-x));
			}
			result.push_back(sol2);
			return;
		}
		for (int j = i; j < s.size(); ++j)
		{
			if (f[i][j])
			{
				sol.push_back(j + 1);
				dfs(j + 1);
				sol.pop_back();
			}
		}
	}

	void find_palindrome(string& s)
	{
		f = vector<vector<bool>>(s.size(), vector<bool>(s.size()));
		for (int i = 0; i < s.length(); ++i)
		{
			for (int j = 0; j < 2; ++j)
			{
				for (int x = i, y = i + j; x >= 0 && y < s.length(); --x, ++y)
				{
					if (s[x] != s[y])
						break;
					f[x][y] = true;
				}
			}
		}
	}
};


//int main()
//{
//	Solution sl;
//	displayVector2(sl.partition("a"));
//
//	system("pause");
//	return 0;
//}