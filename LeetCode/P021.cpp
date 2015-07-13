#include"LeetCode.h"

class Solution {
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode* head=NULL, *tail=NULL;
		ListNode* p;
		while (l1 != NULL&&l2 != NULL)
		{
			if (l1->val < l2->val)
				p = l1, l1 = l1->next;
			else
				p = l2, l2 = l2->next;
			if (head == NULL)
				head = tail = p;
			else
				tail->next = p, tail = p;
		}
		p = (l1 == NULL ? l2 : l1);
		if (head != NULL) 
			tail->next = p;
		else
			head = p;
		return head;
	}
};