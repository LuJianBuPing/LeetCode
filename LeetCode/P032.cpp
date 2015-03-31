#include "LeetCode.h"

class Solution {
public:
	int longestValidParentheses(string s) {
		int* p = new int[s.size()];
		p[0] = -1;

		int max = -1;

		for (int i = 1; i < s.size(); ++i)
		{
			if (s[i] == ')')
			{
				if (s[i - 1] == '(')
					p[i] = i - 1;
				else
				{
					if (p[i - 1] > 0 && s[p[i - 1] - 1] == '(')
						p[i] = p[i - 1] - 1;
					else
						p[i] = -1;
				}

				if (p[i] > 0 && p[p[i] - 1] >= 0)
					p[i] = p[p[i] - 1];

				if (p[i] >= 0 && i - p[i] > max)
					max = i - p[i];
			}
			else
				p[i] = -1;
		}
		delete[] p;
		return max + 1;
	}
};


//int main()
//{
//	Solution sl;
//	cout << sl.longestValidParentheses("()") << endl;
//	cout << sl.longestValidParentheses("()()") << endl;
//	cout << sl.longestValidParentheses("(()") << endl;
//	cout << sl.longestValidParentheses(")()())") << endl;
//	cout << sl.longestValidParentheses(")(()())") << endl;
//	PAUSE;
//}