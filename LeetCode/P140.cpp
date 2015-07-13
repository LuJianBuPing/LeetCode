#include "LeetCode.h"

class Solution {
	int LEN;
	int N;
	vector<int> f;
	vector<vector<int>> next;
	vector<string> result;
public:
	vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
		LEN = N = s.length();
		f = vector<int>(N, -1);
		next = vector<vector<int>>(N);
		for (auto& str : wordDict)
		{
			LEN = max(LEN, (int)str.length());
		}

		if (breaker(s, 0, wordDict))
		{
			findResult(0, "", s);
		}

		return result;
	}

	void findResult(int pos, string sol, string& s)
	{
		if (pos == N)
		{
			result.push_back(sol);
			return;
		}

		for (auto i : next[pos])
		{
			string word = s.substr(pos, i);
			findResult(pos + i, sol + (sol.length()>0 ? " " + word : word), s);
		}
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
				next[pos].push_back(i);
				//break;
			}
		}
		f[pos] = result ? 1 : 0;
		return result;
	}
};