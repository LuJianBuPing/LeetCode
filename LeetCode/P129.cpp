#include "LeetCode.h"

class Solution {
public:
	int sumNumbers(TreeNode* root) {
		int sum = 0;
		helper(root, 0, sum);
		return sum;
	}

	void helper(TreeNode* root, int num, int& sum)
	{
		if (root == NULL)
			return;
		int num1 = num * 10 + root->val;
		if (root->left == NULL&&root->right == NULL)
		{
			sum += num1;
			return;
		}
		helper(root->left, num1, sum);
		helper(root->right, num1, sum);
	}
};