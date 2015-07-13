#include "LeetCode.h"

class Solution {
	vector<vector<bool>> p;
public:
	int minCut(string s) {
		find_palindrome(s);
		vector<int> f(s.size(), INT_MAX);
		f[0] = 0;
		for (int i = 1; i < s.size(); ++i)
		{
			if (p[0][i])
				f[i] = 0;
			else
			for (int j = 0; j < i; ++j)
			{
				if (p[j+1][i])
				f[i] = min(f[i], f[j] + 1);
			}
		}
		return f[s.size()-1];
	}

	void find_palindrome(string& s)
	{
		p = vector<vector<bool>>(s.size(), vector<bool>(s.size()));
		for (int i = 0; i < s.length(); ++i)
		{
			for (int j = 0; j < 2; ++j)
			{
				for (int x = i, y = i + j; x >= 0 && y < s.length(); --x, ++y)
				{
					if (s[x] != s[y])
						break;
					p[x][y] = true;
				}
			}
		}
	}
};

//int main()
//{
//	Solution s;
//
//	cout << s.minCut("aab") << endl;
//
//
//	system("pause");
//}