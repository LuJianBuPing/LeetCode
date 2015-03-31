#include "LeetCode.h"

class Solution {
public:
	int trap(int A[], int n) {
		stack<pair<int, int>> stk;
		int result = 0;
		for (int i = 0; i < n; ++i)
		{
			while (stk.size()>0 && stk.top().first <= A[i])
			{
				int h = stk.top().first;
				stk.pop();
				if (!stk.empty())
				{
					int l = i - stk.top().second - 1;
					h = min(stk.top().first, A[i]) - h;
					result += h*l;
				}
			}
			stk.push(pair<int, int>(A[i], i));
		}
		return result;
	}
};


//int main()
//{
//	int A[] = { 0, 1, 0, 2, 1, 0,  3, 2, 1, 2, 1 };
//	Solution sl;
//	cout << sl.trap(A,11) << endl;
//
//
//	PAUSE;
//}