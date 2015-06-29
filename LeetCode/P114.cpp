#include "LeetCode.h"

class Solution {
public:
	void flatten(TreeNode* root) {
		helper(root);
	}

	TreeNode* helper(TreeNode* root)
	{
		if (root == NULL)
			return NULL;
		auto lt = helper(root->left);
		auto rt = helper(root->right);
		link(root, root, link(root->left, lt, root->right));
		return rt == NULL ? (lt == NULL ? root : lt) : rt;
	}

	TreeNode* link(TreeNode* h1, TreeNode* t1, TreeNode* h2)
	{
		if (h2 == NULL) return h1;
		if (h1 == NULL) return h2;
		t1->right = h2;
		t1->left = NULL;
		return h1;
	}
};