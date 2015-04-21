#include "LeetCode.h"

class Solution{
	TreeNode* pre;
	TreeNode* err1;
	TreeNode* err2;
public:
	void recoverTree(TreeNode *root) {
		pre = err1 = err2 = NULL;
		travel(root);
		swap(err1->val, err2->val);
	}

	void travel(TreeNode* root)
	{
		if (root == NULL)
			return;

		travel(root->left);
		if (pre != NULL && root->val <= pre->val)
		{
			if (err1 == NULL)
				err1 = pre;
			err2 = root;
		}
		pre = root;
		travel(root->right);
	}
};