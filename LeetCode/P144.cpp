#include "LeetCode.h"
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> stk;

		stk.push(root);

		while (!stk.empty())
		{
			TreeNode* node = stk.top();
			stk.pop();
			if (node == NULL)
				continue;
			result.push_back(node->val);
			stk.push(node->right);
			stk.push(node->left);
		}

		return result;
	}
};