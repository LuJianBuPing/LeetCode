#include "LeetCode.h"

typedef SListNode ListNode;

class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		ListNode* result = NULL, *tail = NULL, *p = head;

		while (p != NULL)
		{
			ListNode* q = p;

			if (p->next != NULL&&p->val == p->next->val)
			{
				ListNode* q = p;
				while (q != NULL&&q->val == p->val)
					q = q->next;
				p = q;
			}
			else
				p = p->next;

			q->next = NULL;
			if (result == NULL)
				result = tail = q;
			else
			{
				tail->next = q;
				tail = q;
			}
		}

		return result;
	}
};
