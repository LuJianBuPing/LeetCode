#include "LeetCode.h"



class Solution {
public:
	ListNode* sortList(ListNode* head) {
		vector<pair<ListNode*, int>> stk;

		while (head != NULL)
		{
			{
				auto p = head;
				auto q = head->next;
				if (q != NULL)
				{
					head = q->next;
					if (q->val < p->val)
					{
						q->next = p;
						p->next = NULL;
						stk.push_back(pair<ListNode*, int>(q, 2));
					}
					else
					{
						q->next = NULL;
						stk.push_back(pair<ListNode*, int>(p, 2));
					}
				}
				else
				{
					stk.push_back(pair<ListNode*, int>(p, 1));
					head = q;
				}
			}

			while (stk.size()>1)
			{
				auto& list1 = stk[stk.size() - 2];
				auto& list2 = stk[stk.size() - 1];

				if (head == NULL || list1.second <= list2.second)
				{
					ListNode* p = list1.first;
					ListNode* q = list2.first;
					ListNode* h = NULL, *t = NULL, *c;
					while (p != NULL&&q != NULL)
					{
						if (p->val <= q->val)
						{
							c = p;
							p = p->next;
						}
						else
						{
							c = q;
							q = q->next;
						}

						if (h == NULL)
						{
							h = t = c;
						}
						else
						{
							t->next = c;
							t = c;
						}
					}

					if (p != NULL)
					{
						t->next = p;
					}

					if (q != NULL)
					{
						t->next = q;
					}

					list1.first = h;
					list1.second += list2.second;
					stk.pop_back();
				}
				else break;
			}
		}


		return stk.size() == 1 ? stk[0].first : NULL;
	}
};

//int main()
//{
//	Solution sl;
//	displayList(sl.sortList(makeList(vector<int>({ 4, 19, 14, 5, -3, 1, 8, 5, 11, 15,-9 }))));
//
//	system("pause");
//	return 0;
//}