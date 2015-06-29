#include "LeetCode.h"

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		auto pit = preorder.begin();
		return buildTree(pit, inorder.begin(), inorder.end());
	}

	TreeNode* buildTree(vector<int>::iterator& pit, vector<int>::iterator is, vector<int>::iterator ie)
	{
		if (is == ie)
			return NULL;
		auto it = find(is, ie, *pit);

		if (it != ie)
		{
			auto node = new TreeNode(*pit);
			++pit;
			node->left = buildTree(pit, is, it);
			node->right = buildTree(pit, it + 1, ie);
			return node;
		}
		else
			return NULL;
	}
};