#include "LeetCode.h"

class Solution {
	vector<vector<int>> result;
	vector<int> sol;
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		findPathSum(root, sum);
		return result;
	}

	void findPathSum(TreeNode* root, int sum) {
		if (root == NULL)
			return;
		sol.push_back(root->val);
		if (sum == root->val && root->left == NULL && root->right == NULL)
		{
			result.push_back(sol);
		}
		else
		{
			findPathSum(root->left, sum - root->val);
			findPathSum(root->right, sum - root->val);
		}
		sol.pop_back();
	}
};
