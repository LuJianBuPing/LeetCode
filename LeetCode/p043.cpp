#include "LeetCode.h"

class Solution {
public:
	string multiply(string num1, string num2) {
		int lena = num1.length(), lenb = num2.length(), len = lena + lenb;
		int* a = new int[lena];
		int* b = new int[lenb];
		int* c = new int[len];
		memset(c, 0, sizeof(int)*(lena + lenb));
		for (int i = 0; i < num1.length(); ++i)
			a[lena - 1 - i] = num1[i] - '0';
		for (int i = 0; i < num2.length(); ++i)
			b[lenb - 1 - i] = num2[i] - '0';

		for (int i = 0; i < lena; ++i)
			for (int j = 0; j < lenb; ++j)
				c[i + j] += a[i] * b[j];

		for (int i = 0; i < len - 1; ++i)
		{
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
		}
		while (len>1&&c[len - 1] == 0)
			--len;

		string result;

		for (int i = 0; i < len; ++i)
			result.push_back('0' + c[len - 1 - i]);
		return result;
	}
};

//
//int main()
//{
//	Solution sl;
//
//	cout << sl.multiply("9", "9") << endl;
//	cout << sl.multiply("11", "0") << endl;
//
//	PAUSE;
//}