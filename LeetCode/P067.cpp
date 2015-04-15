#include "LeetCode.h"

class Solution {
public:
	string addBinary(string a, string b) {
		int lena = a.length();
		int lenb = b.length();
		int lenc = max(lena, lenb);

		string result(lenc, 0);

		int c = 0;
		for (int i = 0; i < lenc; ++i)
		{
			int ai = lena - 1 - i;
			int bi = lenb - 1 - i;

			int ax = ai >= 0 ? a[ai] - '0' : 0;
			int bx = bi >= 0 ? b[bi] - '0' : 0;

			int cx = ax + bx + c;
			if (cx > 1)
				cx -= 2, c = 1;
			else
				c = 0;

			result[lenc - 1 - i] = '0' + cx;
		}
		if (c == 1)
			result.insert(result.begin(), '1');
		return result;
	}
};

//int main()
//{
//
//	PAUSE;
//}