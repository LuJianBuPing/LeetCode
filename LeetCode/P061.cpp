#include "LeetCode.h"



class Solution {
public:
	ListNode *rotateRight(ListNode *head, int k) {
		if (head == NULL || head->next == NULL || k==0)
			return head;
		int len = 0;
		auto tail = head;
		for (auto p = head; p != NULL; p = p->next)
		{
			++len;
			tail = p;
		}
		if (k%len == 0)
			return head;

		auto p = head;
		for (int skip = len - (k%len); skip > 1; --skip)
			p = p->next;

		auto newhead = p->next;
		p->next = NULL;
		tail->next = head;
		
		return newhead;
	}
};

//int main()
//{
//	auto l = makeList(vector<int>({ 1, 2, 3, 4, 5 }));
//
//	Solution sl;
//
//	displayList(sl.rotateRight(l, 2));
//
//
//	PAUSE;
//}