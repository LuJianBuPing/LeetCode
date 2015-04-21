#include "LeetCode.h"


class Solution {
	vector<string> result;
	string s;
	int sol[4];
public:
	vector<string> restoreIpAddresses(string s) {
		this->s = s;
		restore(0, 0);
		return result;
	}

	void restore(int n, int pos)
	{
		if (n == 4)
		{
			if (pos != s.length())
				return;
			string str;
			for (int i = 0; i < 4; ++i)
			{
				if (i>0) str.push_back('.');
				str += std::to_string(sol[i]);
			}
			result.push_back(str);
			return;
		}

		int val = 0;
		for (int i = pos; i < s.length(); ++i)
		{
			val = val * 10 + s[i] - '0';
			if (val >= 256)
				break;
			else
			{
				sol[n] = val;
				restore(n + 1, i + 1);
			}

			if (val==0 && s[i] == '0')
				break;
		}
	}
};