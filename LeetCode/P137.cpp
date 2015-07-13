#include "LeetCode.h"

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int twos = 0, threes = 0, ones=0;

		for (int x:nums)
		{
			int ot = threes;
			threes = twos&x | ~(threes&x)&threes;
			twos = ones&x | ~(twos&x)&twos;
			ones = ot&x | (x|ones)&~twos&~threes;
		}
		return ones;
	}
};


//int main()
//{
//
//	Solution sl;
//
//	cout << sl.singleNumber(vector<int>({ 0, 1, 0, 1, 0, 1, 99})) << endl;
//
//	system("pause");
//	return 0;
//}