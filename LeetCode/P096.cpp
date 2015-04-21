#include "LeetCode.h"

class Solution {
public:
	int numTrees(int n) {
		return C(2 * n, n) / (n + 1);
	}

	uint64_t C(uint32_t m, uint32_t n)
	{
		uint64_t result = 1;
		uint32_t m_n = m - n;
		if (m_n > n) swap(n, m_n);

		for (uint32_t i = 0; i < m_n; ++i)
		{
			result *= (m - i);
			while (n>1 && result%n == 0)
			{
				result /= n;
				--n;
			}
		}
		return result;
	}
};

//int main()
//{
//	Solution sl;
//
//	cout << sl.numTrees(19) << endl;
//
//	PAUSE;
//}