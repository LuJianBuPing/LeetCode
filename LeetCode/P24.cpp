#include "LeetCode.h"

typedef SListNode ListNode;

class Solution {
public:
	ListNode *swapPairs(ListNode *head) {
		ListNode* h = new ListNode(0),*p=h;
		h->next = head;

		for (;;)
		{
			auto p1 = p->next;
			if (p1 == NULL) break;
			auto p2 = p1->next;
			if (p2 == NULL) break;

			p->next = p2;
			p1->next = p2->next;
			p2->next = p1;
			p = p1;
		}

		p = h->next;
		delete h;
		return p;
	}
};
//
//int main()
//{
//	ListNode* head = makeList(vector<int>({1,2,3,4,5}));
//	Solution sl;
//
//	displayList(sl.swapPairs(head));
//	displayList(sl.swapPairs(makeList(vector<int>())));
//
//	PAUSE;
//}