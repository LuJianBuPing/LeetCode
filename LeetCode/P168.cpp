#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
	string convertToTitle(int n) {
		char result[11];
		int k = 0;
		long long numnum = 26;
		while (n>numnum)
		{
			n -= numnum;
			numnum *= 26;
			++k;
		}
		--n;
		result[k+1] = 0;

		for (int i = 0; i <= k; ++i)
		{
			result[k - i] = 'A' + n % 26;
			n /= 26;
		}
		return result;
	}
};

//int main()
//{
//	Solution sl;
//	cout << sl.convertToTitle(53) << endl;
//	cout << sl.convertToTitle(703) << endl;
//	system("pause");
//}