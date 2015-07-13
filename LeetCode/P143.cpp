#include "LeetCode.h"



class Solution {
public:
	void reorderList(ListNode* head) {
		if (head == NULL)
			return;
		int len = 0;
		for (auto p = head; p != NULL; p = p->next)
		{
			++len;
		}

		auto p = head;
		ListNode* h2 = NULL;
		for (int i = 0; i<len; ++i)
		{
			auto q = p->next;
			if (i>(len - 1) / 2)
			{

				p->next = h2;
				h2 = p;
			}
			else if (i == (len - 1) / 2)
			{
				p->next = NULL;
			}
			p = q;
		}

		auto nt = head;
		auto h1 = head->next;

		while (h1 != NULL || h2 != NULL)
		{
			if (h2 != NULL)
			{
				nt->next = h2;
				nt = h2;
				h2 = h2->next;
			}

			if (h1 != NULL)
			{
				nt->next = h1;
				nt = h1;
				h1 = h1->next;
			}
		}
	}
};