#include "LeetCode.h"

typedef SListNode ListNode;

class Solution {
public:
	ListNode *partition(ListNode *head, int x) {
		ListNode* less = new ListNode(0), *ltail = less;
		ListNode* greater = new ListNode(0), *gtail = greater;

		for (auto p = head; p != NULL; p = p->next)
		{
			if (p->val < x)
			{
				ltail->next = p;
				ltail = p;
			}
			else{
				gtail->next = p;
				gtail = p;
			}
		}

		ltail->next = greater->next;
		gtail->next = NULL;
		return ltail->next;
	}
};