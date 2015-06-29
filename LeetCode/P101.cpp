#include "LeetCode.h"

class Solution {
public:
	bool isSymmetric(TreeNode *root) {
		if (root == NULL)
			return true;
		return isSymmetricTree(root->left, root->right);
	}

	bool isSymmetricTree(TreeNode *p, TreeNode *q) {
		if (!sameValue(p, q))
			return false;
		if (p == NULL)
			return true;

		return isSymmetricTree(p->left, q->right) && isSymmetricTree(p->right, q->left);
	}

	bool sameValue(TreeNode *p, TreeNode *q)
	{
		if (p == NULL && q == NULL)
			return true;
		if (p == NULL || q == NULL)
			return false;
		return p->val == q->val;
	}
};