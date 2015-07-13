#include "LeetCode.h"

class Solution{

public:
	int maxProfit(vector<int>& prices) {
		int result = 0;

		int m = prices.size()>0?prices[0]:0;
		for (int i = 1; i < prices.size(); ++i)
		{
			result = max(result, prices[i] - m);
			m = min(prices[i], m);
		}

		return result;
	}
};


//didn't catch the problem
class Solution2 {
public:
	int maxProfit(vector<int>& prices) {
		int N = prices.size();
		vector<vector<int>> f(2, vector<int>(N+2, -1000000000));

		int cur = 0;
		f[cur][0] = 0;

		for (int i = 1; i <= N; ++i)
		{
			int price = prices[i - 1];
			cur = 1 - cur;
			for (int j = 0; j <= i; ++j)
			{
				f[cur][j] = max(f[1-cur][j],f[1-cur][j+1]+price);
				if (j>0)
					f[cur][j] = max(f[cur][j], f[1 - cur][j - 1] - price);
			}
		}

		int result = 0;
		for (int i = 0; i <= N; ++i)
			result = max(result, f[cur][i]);
		return result;
	}
};

//int main()
//{
//	Solution sl;
//	cout << sl.maxProfit(vector<int>({ 1, 1, 1, 1, 2 })) << endl;
//
//	system("pause");
//}