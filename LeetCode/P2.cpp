#include<iostream>
using namespace std;

/**
 Definition for singly-linked list.*/
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode* head = NULL;
		ListNode* tail = NULL;
		int carry = 0;

		while (l1 != NULL || l2 != NULL || carry!=0)
		{
			int sum = carry;
			if (l1 != NULL)
			{
				sum += l1->val;
				l1 = l1->next;
			}
			if (l2 != NULL)
			{
				sum += l2->val;
				l2 = l2->next;
			}

			if (sum > 9)
			{
				carry = 1;
				sum -= 10;
			}
			else
				carry = 0;

			ListNode* node = new ListNode(sum);

			if (head == NULL)
				head = tail = node;
			else
			{
				tail->next = node;
				tail = node;
			}
		}

		return head;
	}
};