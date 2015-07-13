#include "LeetCode.h"

//Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		unordered_map<RandomListNode*, RandomListNode*> o2n;
		RandomListNode* newhead = NULL, *tail = NULL;
		for (auto h = head; h != NULL; h = h->next)
		{
			auto p = new RandomListNode(h->label);
			o2n[h] = p;
			if (newhead == NULL)
			{
				newhead = tail = p;
			}
			else
			{
				tail->next = p;
				tail = p;
			}
		}

		for (auto h1 = head, h2 = newhead; h1 != NULL; h1 = h1->next, h2 = h2->next)
		{
			if (h1->random != NULL)
				h2->random = o2n[h1->random];
		}

		return newhead;
	}
};