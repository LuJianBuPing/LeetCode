#include "LeetCode.h"

class Solution {
public:
	string minWindow(string S, string T) {
		int charReq[256];
		int charApe[256];
		bool charSat[256];
		int numSat = 0;
		int num = 0;

		int start = 0;
		int minlen = S.length() + 1;
		int minstart = 0;

		memset(charReq, 0, sizeof(charReq)); 
		memset(charApe, 0, sizeof(charApe));
		memset(charSat, 0, sizeof(charSat));

		for (char ch : T)
			charReq[ch]++;

		for (int x:charReq)
			if (x != 0)
				++num;

		for (int i = 0; i < S.length(); ++i)
		{
			charApe[S[i]]++;

			if (charApe[S[i]] >= charReq[S[i]] && charReq[S[i]]>0 && charSat[S[i]] == false)
			{
				charSat[S[i]] = true;
				++numSat;
				//cout << "aaaa" << numSat << endl;
			}
			while (charApe[S[start]] > charReq[S[start]])
			{
				--charApe[S[start]];
				++start;
				//cout << "bbbb" << endl;
			}
			if (numSat >= num)
			{
				int len = i - start + 1;
				if (len < minlen)
				{
					minlen = len;
					minstart = start;
					//cout << "cccc" << endl;
				}
			}
		}

		return (numSat >= num) ? S.substr(minstart, minlen) : "";
	}
};

//int main()
//{
//	Solution sl;
//
//	cout << sl.minWindow("ab", "b") << endl;
//
//	PAUSE;
//}