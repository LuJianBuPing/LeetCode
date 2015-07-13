#include "LeetCode.h"



class Solution {
	pair<ListNode*, ListNode*> reverseKNode(ListNode*& head, int& k)
	{
		ListNode* h = NULL, *t = NULL;
		for (; k > 0; --k)
		{
			if (head == NULL)
				break;
			ListNode*p = head;
			head = head->next;
			p->next = h;
			t == NULL ? h = t = p : h = p;
		}
		return make_pair(h, t);
	}

public:
	ListNode *reverseKGroup(ListNode* head, int k) {
		ListNode* h = new ListNode(0), *t = h;

		while (head != NULL)
		{
			int n = k;
			auto group = reverseKNode(head, n);
			if (n != 0)
			{
				head = group.first;
				group = reverseKNode(head, k);
			}

			t->next = group.first;
			t = group.second;
		}
		return h->next;
	}
};
//
//int main()
//{
//	Solution sl;
//	displayList(sl.reverseKGroup(makeList(vector<int>()), 1));
//	displayList(sl.reverseKGroup(makeList(vector<int>({ 1, 2, 3, 4, 5 })), 1));
//	displayList(sl.reverseKGroup(makeList(vector<int>({ 1, 2, 3, 4, 5 })), 2));
//	displayList(sl.reverseKGroup(makeList(vector<int>({ 1, 2, 3, 4, 5 })), 3));
//	displayList(sl.reverseKGroup(makeList(vector<int>({ 1, 2, 3, 4, 5 })), 5));
//
//	PAUSE;
//}