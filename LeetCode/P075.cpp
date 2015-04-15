#include "LeetCode.h"

class Solution {
public:
	void sortColors(int A[], int n) {
		int n0 = 0, n1 = 0;
		for (int i = 0; i < n; ++i)
		{
			int t = A[i];
			A[i] = 2;
			if (t <= 1) A[n1++] = 1;
			if (t <= 0) A[n0++] = 0;
		}
	}
};

//int main()
//{
//
//	PAUSE;
//}