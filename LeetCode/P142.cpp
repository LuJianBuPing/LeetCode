#include "LeetCode.h"



class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		auto fast = head, slow = head;
		bool hasCycle = false;
		while (fast != NULL)
		{
			if (fast->next != NULL)
				fast = fast->next->next;
			else
				break;
			slow = slow->next;
			if (fast == slow)
			{
				hasCycle = true;
				break;
			}
		}

		if (hasCycle)
		{
			auto p = head;
			for (;;)
			{
				if (p == slow)
				{
					return p;
				}
				p = p->next;
				slow = slow->next;
			}
		}

		return NULL;
	}
};