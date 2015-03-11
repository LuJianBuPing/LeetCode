#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int lastpos[256];
		for (int i = 0; i < 256; ++i)
			lastpos[i] = -1;

		int result = 0;
		int start = -1;

		for (int i = 0; i < s.length(); ++i)
		{
			int ch = (unsigned char)s[i];
			if (lastpos[ch]>start)
				start = lastpos[ch];

			lastpos[ch] = i;

			int len = i - start;
			if (len > result)
				result = len;
		}
		return result;
	}
};


/*
int main()
{
	Solution sl;
	string str = "abcd";

	cout << sl.lengthOfLongestSubstring(str) << endl;

	system("pause");
}
*/