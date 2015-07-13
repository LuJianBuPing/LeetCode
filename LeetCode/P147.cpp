#include "LeetCode.h"

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		ListNode* newhead = NULL;
		auto p = head, q = head;

		while (p != NULL)
		{
			q = p->next;
			newhead = insertOneNode(newhead, p);
			p = q;
		}
		return newhead;
	}

	ListNode* insertOneNode(ListNode* head, ListNode* node)
	{
		if (head == NULL || node->val<head->val)
		{
			node->next = head;
			return node;
		}
		for (auto p = head; p != NULL; p = p->next)
		{
			if (p->next == NULL || node->val<p->next->val)
			{
				node->next = p->next;
				p->next = node;
				break;
			}
		}
		return head;
	}
};