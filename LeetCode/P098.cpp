#include "LeetCode.h"

class Solution {
	vector<int> traverse;
public:
	bool isValidBST(TreeNode *root) {
		travel(root);

		for (int i = 1; i < traverse.size(); ++i)
		{
			if (traverse[i] <= traverse[i - 1])
				return false;
		}
		return true;
	}

	void travel(TreeNode* root)
	{
		if (root == NULL)
			return;

		travel(root->left);
		traverse.push_back(root->val);
		travel(root->right);
	}
};

class Solution2{
	TreeNode* pre;
public:
	bool isValidBST(TreeNode *root) {
		pre = NULL;
		return travel(root);
	}

	bool travel(TreeNode* root)
	{
		if (root == NULL)
			return true;
		if (!travel(root->left))
			return false;
		if (pre!=NULL && root->val <= pre->val)
			return false;
		else
			pre = root;
		if (!travel(root->right))
			return false;
		return true;
	}
};