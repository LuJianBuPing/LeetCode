#include "LeetCode.h"

class Solution {
public:
	int minDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		int hl = minDepth(root->left);
		int hr = minDepth(root->right);

		if (hl == 0)
			return hr + 1;
		else if (hr == 0)
			return hl + 1;
		else
			return min(hl, hr) + 1;
	}
};