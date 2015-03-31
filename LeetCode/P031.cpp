#include "LeetCode.h"

class Solution {
public:
	void nextPermutation(vector<int> &num) {
		int i, j;
		for (i = num.size() - 1; i > 0; --i)
			if (num[i] > num[i - 1])
				break;

		if (i > 0)
		{
			for (j = num.size()-1; j>=i; --j)
				if (num[j]>num[i - 1])
				{
					swap(num[j], num[i - 1]);
					break;
				}
		}
		for (j = num.size() - 1; i < j; ++i, --j)
			swap(num[i], num[j]);
	}
};


//int main()
//{
//	Solution sl;
//	vector<int> num = {1,2,3};
//	sl.nextPermutation(num);
//	displayVector(num);
//
//	num = { 3, 2, 1 };
//	sl.nextPermutation(num);
//	displayVector(num);
//
//	num = { 1, 1, 5 };
//	sl.nextPermutation(num);
//	displayVector(num);
//
//	num = { 1, 2, 4, 3};
//	sl.nextPermutation(num);
//	displayVector(num);
//
//	PAUSE;
//}