#include "LeetCode.h"

class Solution {
public:
	bool isPalindrome(string s) {
		
		bool result = true;

		for (int i = 0, j = s.length() - 1; i < j;++i,--j)
		{
			while (i < s.length() && !isalnum(s[i])) ++i;
			while (j >= 0 && !isalnum(s[j])) --j;
			if (j >= 0 && i < s.length())
			{
				if (tolower(s[i]) != tolower(s[j]))
				{
					result = false;
					break;
				}
			}
		}

		return result;
	}
};