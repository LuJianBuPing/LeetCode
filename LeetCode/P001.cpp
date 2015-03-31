#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
	int cmpInt(int i1, int i2)
	{
		return i1 < i2 ? -1 : (i1>i2 ? 1 : 0);
	}

	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> num(numbers);
		
		sort(num.begin(), num.end());
		int index1 = 0, index2 = num.size() - 1;

		while (index1 < index2)
		{
			int cmp = target - num[index1] - num[index2];

			if (cmp > 0)
				++index1;
			else
				if (cmp < 0)
					--index2;
				else
					break;
		}

		int num1 = num[index1];
		int num2 = num[index2];

		index1 = -1;

		for (int i = 0; i < numbers.size(); ++i)
		{
			if (numbers[i] == num1 && index1 == -1)
				index1 = i;
			if (numbers[i] == num2)
				index2 = i;
		}

		if (index1 > index2)
		{
			int t = index2;
			index2 = index1;
			index1 = t;
		}

		vector<int> result;
		result.push_back(index1 + 1);
		result.push_back(index2 + 1);

		return result;
	}
};

/*
int main()
{
	Solution sl;

	vector<int> numbers = { 2, 7, 11, 15 };
	int target = 9;

	auto result = sl.twoSum(numbers, target);

	cout << result[0] << ", " << result[1] << endl;

	system("pause");
}
*/