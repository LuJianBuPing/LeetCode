#include "LeetCode.h"

class Solution {
	int f[2][65536];
public:
	int numDistinct(string s, string t) {
		memset(f, 0, sizeof(f));

		int cur = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			cur = 1 - cur;
			for (int j = 0; j < t.length() && j <= i; ++j)
			{
				f[cur][j] = f[1 - cur][j];
				if (s[i] == t[j])
					f[cur][j] += (j > 0) ? f[1 - cur][j - 1] : 1;
				//f[i][j] = i > 0 ? f[i - 1][j] : 0;
				//if (s[i] == t[j])
				//	f[i][j] += (i>0&&j>0)?f[i - 1][j - 1]:0;
			}
		}
		return f[cur][t.length() - 1];
	}
};

//
//int main()
//{
//
//	Solution sl;
//
//	cout << sl.numDistinct("bbb", "bb") << endl;
//	system("pause");
//	return 0;
//}