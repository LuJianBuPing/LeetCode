#include<iostream>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		int sign = 1;
		long long result = 0;
		if (x < 0)
		{
			sign = -1;
			x = -x;
		}

		while (x > 0)
		{
			result = result * 10 + x % 10;
			x /= 10;
		}

		if (result > 2147483647)
			return 0;
		else
			return (sign == -1) ? -result : result;
	}
};

//int main()
//{
//	Solution sl;
//	cout << sl.reverse(123) << endl;
//	cout << sl.reverse(12300) << endl;
//	cout << sl.reverse(-123) << endl;
//	cout << sl.reverse(2147483647) << endl;
//	system("pause");
//}