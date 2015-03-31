#include "LeetCode.h"

class Solution {
	char buffer[2][65536];
public:
	string countAndSay(int n) {
		char* str = buffer[0], *n_str = buffer[1];
		strcpy(str, "1");

		for (int i = 1; i < n; ++i)
		{
			int str_len = strlen(str);
			int len = 0, k=0;
			for (int j = 0; j < str_len; j = k)
			{
				char ch = str[j];
				int num = 1;
				for (k = j + 1; k < str_len; ++k)
				{
					if (str[j] != str[k])
						break;
					else
						++num;
				}
				sprintf(n_str + len, "%d%c", num, ch);
				len += strlen(n_str + len);
			}
			swap(str, n_str);
		}
		return string(str);
	}
};


//int main()
//{
//	Solution sl;
//	cout << sl.countAndSay(1) << endl;
//	cout << sl.countAndSay(2) << endl;
//	cout << sl.countAndSay(3) << endl;
//	cout << sl.countAndSay(4) << endl;
//	cout << sl.countAndSay(5) << endl;
//	cout << sl.countAndSay(30).length() << endl;
//	PAUSE;
//
//
//}