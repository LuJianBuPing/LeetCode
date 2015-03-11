#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		if (num.size() <= 3)
			return accumulate(num.begin(), num.end(),0);
		int mindiff = INT_MAX;
		int result = 0;

		sort(num.begin(),num.end());
		for (int i = 0; i < num.size(); ++i)
		{
			int tt = target - num[i];
			int j = i + 1, k = num.size() - 1;
			while (j < k)
			{
				int s = num[j] + num[k];
				if (s == tt)
					return target;
				else
				{
					int diff = abs(tt - s);
					if (diff < mindiff)
					{
						mindiff = diff;
						result = num[i] + num[j] + num[k];
					}
					s < tt ? ++j : --k;
				}
			}
		}
		return result;
	}
};