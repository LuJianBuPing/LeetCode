#include "LeetCode.h"

class Solution {
public:
	int lengthOfLastWord(const char *s) {
		auto p = s;

		int len = 0, pos = 0,result = 0;
		while (*p)
		{
			++len;
			if (*p == ' ')
				pos = len;
			else
				result = len - pos;
			++p;
		}

		return result;
	}
};

//int main()
//{
//	Solution sl;
//
//	cout << sl.lengthOfLastWord("   ") << endl;
//
//	PAUSE;
//}