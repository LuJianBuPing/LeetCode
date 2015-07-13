#include "LeetCode.h"



class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		int len=0;
		for (auto p = head; p != NULL; ++len, p = p->next);

		return sortedListToBST(head, 0, len - 1);
	}

	TreeNode* sortedListToBST(ListNode*& head, int i, int j) {
		if (i > j)
			return NULL;

		int mid = (i + j) / 2;
		TreeNode* node = new TreeNode(0);
		node->left = sortedListToBST(head, i, mid - 1);
		node->val = head->val;
		head = head->next;
		node->right = sortedListToBST(head, mid + 1, j);
		return node;
	}
};