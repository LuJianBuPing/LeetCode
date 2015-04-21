#include "LeetCode.h"

class Solution {
public:
	int numDecodings(string s) {
		if (s.length() == 0)
			return 0;
		vector<int> f(s.length(), 0);
		f[0] = s[0]>='1'&&s[0]<='9';

		for (int i = 1; i < s.length(); ++i)
		{
			f[i] = (s[i] >= '1'&&s[i] <= '9') ? f[i - 1] : 0;

			string sub = s.substr(i - 1, 2);
			if (sub >= "10" && sub <= "26")
				f[i] += i >= 2 ? f[i - 2] : 1;
		}
		return f[s.length() - 1];
	}
};