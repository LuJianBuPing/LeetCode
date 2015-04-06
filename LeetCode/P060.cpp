#include "LeetCode.h"

class Solution {
public:
	string getPermutation(int n, int k) {
		int radix[12];
		bool appeared[12];
		string result;

		for (int i = 0; i < n; ++i)
			appeared[i] = false;

		radix[0] = 1;
		radix[1] = 1;

		for (int i = 2; i < 12; ++i)
			radix[i] = radix[i - 1] * i;

		--k;
		for (int i = n - 1; i >= 0; --i)
		{
			int t = k / radix[i];
			k = k%radix[i];

			for (int j = 0; j < n; ++j)
			{
				if (appeared[j]) continue;
				if (t == 0)
				{
					result.push_back('1' + j);
					appeared[j] = true;
					break;
				}
				--t;
			}
		}
		return result;
	}
};


//int main()
//{
//	Solution sl;
//
//	for (int k = 1; k <= 6; ++k)
//	{
//		cout << sl.getPermutation(3, k) << endl;
//	}
//
//	PAUSE;
//}