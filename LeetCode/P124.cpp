#include "LeetCode.h"

class Solution {
	int result = 0;
public:
	int maxPathSum(TreeNode* root) {
		result = INT_MIN;
		maxDirectPathSum(root);
		return result;
	}

	int maxDirectPathSum(TreeNode* root) {
		if (root == NULL)
			return 0;

		int res = root->val;
		if (root->left == NULL || root->right == NULL)
		{
			if (root->left != NULL)
				res = root->val + maxDirectPathSum(root->left);
			else if (root->right != NULL)
				res = root->val + maxDirectPathSum(root->right);

			res = max(root->val, res);
			result = max(res, result);

		}
		else {
			int l = maxDirectPathSum(root->left);
			int r = maxDirectPathSum(root->right);
			res = max(root->val, root->val + max(l, r));

			result = max(result, max(root->val + l + r, res));
		}
		return res;
	}
};