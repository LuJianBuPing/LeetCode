#include "LeetCode.h"

class Solution {
public:
	double pow(double x, int n) {
		if (n == 0)
			return 1.0;
		double p = pow(x, n / 2);

		return (n & 1) ? p*p*((n<0)?1/x:x) : p*p;
	}
};