#include "LeetCode.h"

class Solution {
	string s1, s2, s3;
	char f[128][128];
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.length() + s2.length() != s3.length())
			return false;
		this->s1 = s1;
		this->s2 = s2;
		this->s3 = s3;

		memset(f, -1, sizeof(f));

		return isInter(0, 0, 0);
	}

	bool isInter(int i, int j, int k)
	{
		if (k == s3.length())
			return true;
		if (f[i][j] != -1)
			return f[i][j];

		bool result = false;
		if (i < s1.length() && s1[i] == s3[k])
			result = isInter(i + 1, j, k + 1);
		if (result)
			return true;
		if (j < s2.length() && s2[j] == s3[k])
			result = isInter(i, j + 1, k + 1);

		f[i][j] = result;
		return result;
	}
};

//int main()
//{
//	Solution sl;
//
//	cout << sl.isInterleave("a", "", "c") << endl;
//
//	PAUSE;
//}