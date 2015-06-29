#include "LeetCode.h"

class Solution {
public:
	bool isBalanced(TreeNode* root) {
		return height(root) != -1;
	}

	int height(TreeNode* root)
	{
		if (root == NULL)
			return 0;

		int hl = height(root->left);
		int hr = height(root->right);

		if (hl < 0 || hr < 0 || abs(hl - hr)>1)
			return -1;
		else
			return max(hl, hr) + 1;
	}
};