#include "LeetCode.h"

class Solution {
public:
	int strStr(char *haystack, char *needle) {
		int len = strlen(haystack);
		int lenp = strlen(needle);
		if (lenp == 0)
			return 0;

		int* next = makeNext(needle,lenp);


		int i = 0;
		int n = 0;

		while (i < len)
		{
			if (n == -1 || haystack[i] == needle[n])
				++i, ++n;
			else
				n = next[n];

			if (n == lenp)
				return i - lenp;
		}
		return -1;
	}

	int* makeNext(char* pat, int len)
	{
		int* next = new int[len + 1];

		next[0] = -1;
		int i=0;
		int n = -1;
		while (i<len)
		{
			if (n == -1 || pat[n] == pat[i])
			{
				++i; ++n;
				if (pat[i] == pat[n])
					next[i] = next[n];
				else
					next[i] = n;
			}
			else
				n = next[n];
		}
		return next;
	}
};

//int main()
//{
//	Solution sl;
//
//	displayArray(sl.makeNext("abcabcacab",10),10);
//	displayArray(sl.makeNext("aaaaaaaaaa",10), 10);
//
//	cout << sl.strStr("abcabcacab","bcab") << endl;
//	PAUSE;
//}