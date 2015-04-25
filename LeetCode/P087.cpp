#include "LeetCode.h"

int f[32][32][32];
int hash1[32][32];
int hash2[32][32];

class Solution {
	string s1;
	string s2;
	//vector<vector<vector<int>>> f;
public:
	bool isScramble(string s1, string s2) {
		if (s1.length() != s2.length())
			return false;
		this->s1 = s1;
		this->s2 = s2;
		int len = s1.length();

		memset(f, -1, sizeof(f));
		calcHash(s1, hash1);
		calcHash(s2, hash2);
		//f = vector<vector<vector<int>>>(len + 1, vector<vector<int>>(len + 1, vector<int>(len + 1, -1)));

		return scramble(0, 0, len);
	}

	bool scramble(int i, int j, int l)
	{
		if (l == 0)
			return true;
		if (l == 1)
			return s1[i] == s2[j];
		if (f[i][j][l] != -1)
			return f[i][j][l] == 1;

		bool result = false;
		if (hash1[i][l] == hash2[j][l])
		for (int k = 1; k < l; ++k)
		{
			int lenl = k, lenr = l - k;
			if (scramble(i, j, lenl) && scramble(i + lenl, j + lenl, lenr))
				result = true;
			else if (scramble(i, j + lenr, lenl) && scramble(i + lenl, j, lenr))
				result = true;
			if (result)
				break;
		}
		f[i][j][l] = result;

		return result;
	}

	void calcHash(string& s, int hash[32][32])
	{
		memset(hash, 0, sizeof(hash));

		for (int i = 0; i < s.length(); ++i)
		{
			int sum = 0;
			for (int j = 0; j < s.length() - i; ++j)
			{
				hash[i][j] = sum;
				sum += s[i + j] * s[i + j];
			}
			hash[i][s.length() - i] = sum;
		}
	}
};

//int main()
//{
//
//	Solution sl;
//
//	cout << sl.isScramble("abb", "bab") << endl;
//
//	PAUSE;
//}