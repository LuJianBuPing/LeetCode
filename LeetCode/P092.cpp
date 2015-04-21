#include "LeetCode.h"

typedef SListNode ListNode;

class Solution {
public:
	ListNode *reverseBetween(ListNode *head, int m, int n) {
		ListNode* h1 = new ListNode(0), *tail=h1, *h2=NULL;
		int i = 1;
		for (ListNode* p = head; p != NULL; ++i)
		{
			if (i < m || i > n)
				tail->next = p, tail = p, p = p->next;
			else{
				if (i == m)
					h2 = tail, tail = p;
				auto q = p->next;
				p->next = h2->next;
				h2->next = p;
				p = q;
			}
		}
		tail->next = NULL;
		return h1->next;
	}
};