#include "LeetCode.h"

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_map<int, pair<int, int>> bounds;

		int maxlen = 0;

		for (int i = 0; i < nums.size(); ++i)
		{
			int num = nums[i];
			if (bounds.find(num) != bounds.end())
				continue;

			int left = num;
			int right = num;

			if (bounds.find(num - 1) != bounds.end())
			{
				left = bounds[num - 1].first;
			}
			if (bounds.find(num + 1) != bounds.end())
			{
				right = bounds[num + 1].second;
			}

			bounds[left] = make_pair(left, right);
			bounds[nums[i]] = make_pair(left, right);
			bounds[right] = make_pair(left, right);

			if (right - left + 1 > maxlen)
				maxlen = right - left + 1;
		}

		return maxlen;
	}
};