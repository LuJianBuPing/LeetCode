#include "LeetCode.h"

class Solution {
public:
	int maxSubArray(int A[], int n) {
		if (n <= 0)
			return 0;
		int minsum = A[0]<0?A[0]:0, sum = A[0], result = A[0];

		for (int i = 1; i < n; ++i)
		{
			sum += A[i];
			if (sum - minsum > result)
				result = sum - minsum;
			else
			if (sum < minsum)
				minsum = sum;
		}
		return result;
	}
};


//int main()
//{
//	int A[] = { 1000, -2000, -3, 4, -1, 2, 1, -5, 4 };
//
//	Solution sl;
//
//	cout << sl.maxSubArray(A,9) <<endl;
//
//	PAUSE;
//}