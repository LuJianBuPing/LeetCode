#include "LeetCode.h"

class Solution {
public:
	int sqrt(int x) {
		if (x < 0)
			return -1;
		int l = 0, r = min(x, 46340);

		while (l < r)
		{
			int m = (l + r) / 2;
			int s = m*m;
			if (s == x)
				l = r = m;
			else if (s < x)
				l = m+1;
			else
				r = m-1;
		}
		return l*l>x?l-1:l;
	}
};

//int main()
//{
//	Solution sl;
//
//	for (int i = 0; i < 20; ++i)
//		cout << sl.sqrt(i) << endl;
//
//
//	PAUSE;
//}