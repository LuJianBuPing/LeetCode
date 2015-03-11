#include"LeetCode.h"

SListNode* makeList(vector<int> data)
{
	SListNode * head = NULL;
	for (int i = data.size() - 1; i >= 0; --i)
	{
		if (head == NULL)
			head = new SListNode(data[i]);
		else
		{
			auto p = new SListNode(data[i]);
			p->next = head;
			head = p;
		}
	}
	return head;
}

void displayList(SListNode* head)
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