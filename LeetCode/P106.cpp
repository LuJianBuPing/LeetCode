#include "LeetCode.h"

class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		auto pit = postorder.rbegin();
		return buildTree(pit, inorder.begin(), inorder.end());
	}

	TreeNode* buildTree(vector<int>::reverse_iterator& pit, vector<int>::iterator is, vector<int>::iterator ie)
	{
		if (is == ie)
			return NULL;
		auto it = find(is, ie, *pit);

		if (it != ie)
		{
			auto node = new TreeNode(*pit);
			++pit;
			node->right = buildTree(pit, it + 1, ie);
			node->left = buildTree(pit, is, it);
			return node;
		}
		else
			return NULL;
	}
};