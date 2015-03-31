#include "LeetCode.h"

class Solution {
public:
	int divide(int dividend, int divisor) {
		if (divisor == 0 || divisor==-1&&dividend==INT_MIN)
			return INT_MAX;
		unsigned a = abs(dividend), b = abs(divisor);
		unsigned radix = 1, result = 0;

		for (; b < a && (b << 1) <= a; b <<= 1, radix <<= 1);

		for (; radix > 0; radix >>= 1, b >>= 1)
		{
			if (a >= b)
			{
				a -= b;
				result += radix;
			}
		}
		return (dividend<0) != (divisor<0)?-(int)result:result;
	}
};

//int main()
//{
//	cout << ((INT_MIN) / (-1)) << endl;
//	
//	Solution sl;
//
//	cout << sl.divide(3, 3) << endl;
//	cout << sl.divide(106, 3) << endl;
//	cout << sl.divide(INT_MIN, -1) << endl;
//	cout << sl.divide(INT_MIN, 1) << endl;
//
//	cout << sl.divide(-1010369383, INT_MIN) << endl;
//
//	PAUSE;
//}