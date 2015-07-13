#include"LeetCode.h"

ListNode* makeList(vector<int> data)
{
	ListNode * head = NULL;
	for (int i = data.size() - 1; i >= 0; --i)
	{
		if (head == NULL)
			head = new ListNode(data[i]);
		else
		{
			auto p = new ListNode(data[i]);
			p->next = head;
			head = p;
		}
	}
	return head;
}

void displayList(ListNode* head)
{
	cout << "[ ";
	auto p = head;
	while (p)
	{
		if (p != head)
			cout << " , ";
		cout << p->val;
		p = p->next;
	}
	cout << " ]";
}