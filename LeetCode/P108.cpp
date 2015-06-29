#include "LeetCode.h"

class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return sortedArrayToBST(nums, 0, nums.size() - 1);
	}

	TreeNode* sortedArrayToBST(vector<int>& nums, int i, int j) {
		if (i > j)
			return NULL;

		int mid = (i + j) / 2;
		TreeNode* node = new TreeNode(nums[mid]);

		node->left = sortedArrayToBST(nums, i, mid - 1);
		node->right = sortedArrayToBST(nums, mid + 1, j);
		return node;
	}
};