#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		sort(num.begin(), num.end());
		vector<vector<int>> result;
		int prei = INT_MAX, prej = INT_MAX;
		for (int i = 0; i < num.size(); ++i)
		{
			if (i>0 && num[i] == num[i - 1])
				continue;
			int j = i + 1, k = num.size() - 1;
			while (j < k)
			{
				int sum = num[i] + num[j] + num[k];
				if (sum == 0)
				{
					if (prei!=num[i] || prej != num[j])
					{
						result.push_back(vector<int>({ num[i], num[j], num[k] }));
						prei = num[i], prej = num[j];
					}
					++j;
					--k;
				}
				else
					sum < 0 ? ++j : --k;
			}
		}
		return result;
	}
};


//int main()
//{
//	Solution sl;
//
//	auto result = sl.threeSum(vector<int>({ 3, 0, -2, -1, 1, 2 }));
//
//	for (auto& v : result)
//	{
//		for (int i : v)
//		{
//			cout << i << " ";
//		}
//		cout << endl;
//	}
//	system("pause");
//}
