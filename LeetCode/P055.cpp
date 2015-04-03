#include "LeetCode.h"

class Solution {
public:
	bool canJump(int A[], int n) {
		if (n <= 1)
			return n==1;

		for (int pos = 0; pos + A[pos]<n - 1;)
		{
			int m = -1, mi = pos;
			for (int j = pos + 1; j <= pos + A[pos]; ++j)
			{
				if (j + A[j] > m)
				{
					m = j + A[j];
					mi = j;
				}
			}

			if (pos + A[pos] >= mi + A[mi])
				return false;
			pos = mi;
		}
		return true;
	}
};

//int main()
//{
//
//	PAUSE;
//}