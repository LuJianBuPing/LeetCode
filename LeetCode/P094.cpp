#include "LeetCode.h"

class Solution {
	vector<int> result;
public:
	vector<int> inorderTraversal(TreeNode *root) {
		doInorderTraversal(root);
		return result;
	}

	void doInorderTraversal(TreeNode * root)
	{
		if (root == NULL)
			return;
		doInorderTraversal(root->left);
		result.push_back(root->val);
		doInorderTraversal(root->right);
	}
};