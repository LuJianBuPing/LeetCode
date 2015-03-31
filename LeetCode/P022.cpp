#include "LeetCode.h"

class Solution {
	char tempStr[256];
	vector<string>* pResult;
	int n;
public:
	vector<string> generateParenthesis(int n) {
		this->n = n*2;
		vector<string> result;
		pResult = &result;

		doGen(0, 0);

		return std::move(result);
	}

	void doGen(int i, int d)
	{
		if (i == n)
		{
			if (d == 0)
			{
				tempStr[i] = 0;
				pResult->push_back(tempStr);
			}
			return;
		}
		if (d > n - i)
			return;
		tempStr[i] = '(';
		doGen(i + 1, d + 1);
		if (d > 0)
		{
			tempStr[i] = ')';
			doGen(i + 1, d - 1);
		}
	}
};

//int main()
//{
//	Solution sl;
//	displayVector(sl.generateParenthesis(3));
//	system("pause");
//}