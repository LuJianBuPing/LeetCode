#include "LeetCode.h"

class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		int* C = new int[m];
		std::copy(A, A + m, C);
		//std::merge(C, C + m, B, B + n, A);

		int i = 0, j = 0, k = 0;

		for (;;)
		{
			if (i == m)
			{
				std::copy(B + j, B + n, A + k);
				break;
			}
			if (j == n) {
				std::copy(C + i, C + m, A + k);
				break;
			}

			A[k++] = C[i] <= B[j] ? C[i++] : B[j++];
		}
	}
};