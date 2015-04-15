#include "LeetCode.h"

class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		int len = digits.size();
		int c = 0;
		digits[len - 1] += 1;
		for (int i = len - 1; i >= 0; --i)
		{
			digits[i] += c;
			if (digits[i] > 9)
			{
				c = 1;
				digits[i] = 0;
			}
			else
				c = 0;
		}

		if (c == 1)
			digits.insert(digits.begin(), 1);
		return digits;
	}
};

//int main()
//{
//	Solution sl;
//
//	displayVector(sl.plusOne(vector<int>({9,9,9})));
//
//	PAUSE;
//}