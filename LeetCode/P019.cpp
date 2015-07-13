#include"LeetCode.h"


class Solution {
public:
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		auto* p1 = head;

		for (int i = 0; i < n; ++i)
			p1 = p1->next;

		if (p1 == NULL)
			return head->next;

		auto* p2 = head;

		while (p1->next != NULL)
		{
			p1 = p1->next;
			p2 = p2->next;
		}
		p2->next = p2->next->next;

		return head;
	}
};