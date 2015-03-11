#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
	int titleToNumber(string s) {
		int n = 1;
		int len = s.length();
		int radix = 1;
		for (int i = 0; i < len; ++i)
		{
			n += (s[len - i - 1] - 'A')*radix;
			radix *= 26;
			if (i+1!=len)
				n += radix;
		}
		return n;
	}
};

//
//int main()
//{
//	Solution sl;
//	cout << sl.titleToNumber("AAA") << endl;
//	system("pause");
//}