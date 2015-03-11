#include<iostream>
#include<ctype.h>

using namespace std;

class Solution {
	const long long max_int = 2147483647LL;
	const long long min_int = -2147483648LL;
public:
	int atoi(string str) {
		int pos1, pos2;
		for (pos1 = 0; pos1 < str.length(); ++pos1)
			if (!isspace(str[pos1])) break;

		int sign = 1;
		if (pos1 < str.length() && (str[pos1] == '+' || str[pos1] == '-'))
		{
			if (str[pos1] == '-')
				sign = -sign;
			++pos1;
		}

		for (pos2 = pos1; pos2 < str.length(); ++pos2)
			if (!isdigit(str[pos2])) break;

		long long result = 0, limit = sign>0?max_int:max_int+1;

		for (int i = pos1; i < pos2; ++i)
		{
			result = result * 10 + (str[i] - '0');
			if (result>limit)
			{
				result = limit;
				break;
			}
		}
		return sign > 0 ? result : -result;
	}
};


//int main()
//{
//	Solution sl;
//	cout << sl.atoi("                   -2147483648xxxxxxxxxxxxx aaaaaaaaaaaaaaaaaa") << endl;
//	cout << sl.atoi("123 3213") << endl;
//	cout << sl.atoi("+-+-+-123 3213") << endl;
//	cout << sl.atoi("+-+-123 3213") << endl;
//	cout << sl.atoi("+-+-") << endl;
//	cout << sl.atoi("2147483648") << endl;
//	cout << sl.atoi("-2147483648888888888888888888888") << endl;
//	system("pause");
//}