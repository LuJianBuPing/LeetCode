#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<functional>
#include<numeric>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<stack>
#include<queue>
#include<cstdint>

#define PAUSE system("pause");

using namespace std;

template<class T>
void displayVector(vector<T> vec);

template<class T>
void displayVector2(vector<vector<T>> vec);

template<class T>
void displayArray(T A, int n);

template<class T>
void displayVector(vector<T> vec)
{
	cout << "[ ";
	for (int i = 0; i < vec.size(); ++i)
	{
		if (i != 0)
			cout << " , ";
		cout << vec[i];
	}
	cout << " ]";
}

template<class T>
void displayVector2(vector<vector<T>> vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		displayVector<T>(vec[i]);
		cout << endl;
	}
}

template<class T>
void displayArray(T A, int n)
{
	cout << "[ ";
	for (int i = 0; i < n; ++i)
	{
		if (i != 0)
			cout << " , ";
		cout << A[i];
	}
	cout << " ]";
}


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* makeList(vector<int> data);

void displayList(ListNode* head);

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};