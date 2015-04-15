#include "LeetCode.h"

class Solution {
public:
	int minDistance(string word1, string word2) {

		vector<int> f[2] = { vector<int>(word2.size() + 1, 0), vector<int>(word2.size() + 1, 0) };

		//for (int i = 0; i < word1.size(); ++i)
		//	f[i + 1][0] = i + 1;
		for (int j = 0; j < word2.size(); ++j)
			f[0][j + 1] = j + 1;

		int cur = 0;
		for (int i = 1; i <= word1.size(); ++i)
		{
			cur = 1 - cur;
			f[cur][0] = i;
			for (int j = 1; j <= word2.size(); ++j)
			{
				if (word1[i - 1] == word2[j - 1])
					f[cur][j] = f[1-cur][j - 1];
				else
				{
					int v = f[1-cur][j - 1];
					if (f[1-cur][j] < v)
						v = f[1-cur][j];
					if (f[cur][j - 1] < v)
						v = f[cur][j - 1];

					f[cur][j] = v + 1;
				}
			}
		}

		return f[cur][word2.size()];
	}
};

//int main()
//{
//	Solution sl;
//
//	cout << sl.minDistance("sea","eat") << endl;
//	PAUSE;
//}