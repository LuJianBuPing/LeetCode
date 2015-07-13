#include "LeetCode.h"

class Solution {
	int LEN;
	int N;
	vector<int> f;
public:
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		LEN = N = s.length();
		f = vector<int>(N, -1);
		for (auto& str : wordDict)
		{
			LEN = max(LEN, (int)str.length());
		}

		return breaker(s, 0, wordDict);
	}

	bool breaker(string& s, int pos, unordered_set<string>& wordDict)
	{
		if (pos == N)
			return true;
		if (f[pos] >= 0)
			return f[pos] == 1;
		bool result = false;
		for (int i = 1; i <= LEN&&pos + i <= N; ++i)
		{
			if (!breaker(s, pos + i, wordDict)) continue;
			string sub = s.substr(pos, i);
			if (wordDict.find(sub) != wordDict.end())
			{
				result = true;
				break;
			}
		}
		f[pos] = result ? 1 : 0;
		return result;
	}
};