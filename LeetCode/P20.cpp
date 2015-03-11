#include"LeetCode.h"

class Solution {
public:
	bool isValid(string s) {
		stack<char> stk;
		for (auto ch : s)
		{
			if (!stk.empty()&&(stk.top() + 1 == ch || stk.top() + 2 == ch))
				stk.pop();
			else
				stk.push(ch);
		}
		return stk.empty();
	}
};