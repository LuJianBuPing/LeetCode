#include "LeetCode.h"

class Solution {
public:
	void connect(TreeLinkNode *root) {
		TreeLinkNode* head = root;
		while (head != NULL)
		{
			auto p = head;
			head = NULL;
			auto tail = head;

			for (; p != NULL; p = p->next)
			{
				processNode(p->left, head, tail);
				processNode(p->right, head, tail);
			}
		}
	}

	void processNode(TreeLinkNode* node, TreeLinkNode*& head, TreeLinkNode*& tail){
		if (node == NULL)
			return;
		if (head == NULL)
			head = tail = node;
		else
		{
			tail->next = node;
			tail = node;
		}
	}
};