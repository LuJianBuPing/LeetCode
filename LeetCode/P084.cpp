#include "LeetCode.h"

class Solution {
public:
	int largestRectangleArea(vector<int>& height) {
		stack<pair<int, int>> stk;
		int result = 0;

		height.push_back(0);
		stk.push(make_pair(-1,-1));
		
		for (int i = 0; i < height.size(); ++i)
		{
			while (stk.top().second >= height[i])
			{
				int h = stk.top().second;
				stk.pop();
				result = max(result, h*(i-stk.top().first-1));
			}
			stk.push(make_pair(i, height[i]));
		}

		return result;
	}
};

class Solution2 {
public:
	int largestRectangleArea(vector<int>& height) {
		if (height.size() == 0) return 0;

		stack<pair<int, int>> stk;
		vector<int> areai(height);
		
		for (int i = 0; i < height.size(); ++i)
		{
			int j = i;
			while (!stk.empty() && stk.top().second >= height[i])
				j = stk.top().first, stk.pop();
			stk.push(make_pair(j, height[i]));
			areai[i] += (i-j)*height[i];
		}

		stk = stack<pair<int, int>>();

		for (int i = height.size() - 1; i >= 0; --i)
		{
			int j = i;
			while (!stk.empty() && stk.top().second >= height[i])
				j = stk.top().first, stk.pop();
			stk.push(make_pair(j, height[i]));
			areai[i] += (j - i)*height[i];
		}

		return *max_element(areai.begin(),areai.end());
	}
};

//int main()
//{
//	Solution sl;
//
//	cout << sl.largestRectangleArea(vector<int>({9,9,9,9})) << endl;;
//
//	PAUSE;
//}