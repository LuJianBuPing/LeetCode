#include "LeetCode.h"

class Solution {
public:
	vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int>> result;
		traversal(root, 0, result);
		return result;
	}

	void traversal(TreeNode* root, int level, vector<vector<int>>& result)
	{
		if (root == NULL)
			return;
		if (result.size() <= level)
			result.push_back(vector<int>());
		result[level].push_back(root->val);
		traversal(root->left, level + 1, result);
		traversal(root->right, level + 1, result);
	}
};

