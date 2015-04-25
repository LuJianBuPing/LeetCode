#include "LeetCode.h"

class Solution {
public:
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int>> result;
		traversal(root, 0, result);
		for (int i = 0; i < result.size(); ++i)
		{
			if (i % 2 == 1)
				reverse(result[i].begin(), result[i].end());
		}

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

