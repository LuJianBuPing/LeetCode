#include"LeetCode.h"


struct ListNodeCmp{
	bool operator()(ListNode* a, ListNode* b)
	{
		return a->val > b->val;
	}
};

class Solution {
public:
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		priority_queue<ListNode*, deque<ListNode*>, ListNodeCmp> node_queue;
		ListNode* head = NULL, *tail=NULL;
		for (auto p : lists)
		{
			if (p != NULL)
				node_queue.push(p);
		}

		while (!node_queue.empty())
		{
			auto p = node_queue.top();
			node_queue.pop();

			if (head == NULL)
				head = tail = p;
			else
				tail->next = p, tail = p;
			if (p->next != NULL)
				node_queue.push(p->next);
		}

		return head;
	}
};