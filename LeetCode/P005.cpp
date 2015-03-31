#include<string>
#include<iostream>
using namespace std;


class Solution {
public:
	string longestPalindrome(string s) {
		int maxLen = 0, maxStart = 0;

		for (int i = 0; i < s.length(); ++i)
		{
			int left = i, right = i;
			while (left >= 0 && right < s.length() && s[left] == s[right])
			{
				if (right - left + 1 > maxLen)
				{
					maxLen = right - left + 1;
					maxStart = left;
				}
				--left;
				++right;
			}
			left = i, right = i+1;
			while (left >= 0 && right < s.length() && s[left] == s[right])
			{
				if (right - left + 1 > maxLen)
				{
					maxLen = right - left + 1;
					maxStart = left;
				}
				--left;
				++right;
			}
		}
		return s.substr(maxStart, maxLen);
	}

	string longestPalindrome1(string s) {
		int len = s.length();
		char s1[1024];
		char s2[1024];
		int* f[1024];

		int* temp = new int[len*len];

		for (int i = 0; i < 1024; ++i)
			f[i] = &temp[i*len];
		
		int maxlen = 0, maxi = 0, maxj = 0;

		strcpy(s1, s.c_str());
		for (int i = 0; i < len; ++i)
			s2[len - i - 1] = s1[i];

		for (int i = 0; i < len; ++i)
		{
			for (int j = 0; j < len; ++j)
			{
				if (s1[i] == s2[j])
				{
					if (i == 0 || j == 0)
						f[i][j] = 1;
					else
						f[i][j] = f[i - 1][j - 1] + 1;
				}
				else
					f[i][j] = 0;

				if (f[i][j] > maxlen)
				{
					int x = i - f[i][j] + 1;
					int y = i;
					bool flag = true;

					while (x <= y)
					{
						if (s1[x] != s1[y])
						{
							flag = false;
							break;
						}

						++x;
						--y;
					}

					if (flag)
					{
						maxlen = f[i][j];
						maxi = i;
						maxj = j;
					}
				}
			}
		}
		delete[] temp;

		return s.substr(maxi - maxlen + 1, maxlen);
	}
};

//int main()
//{
//	Solution sl;
//
//	cout << sl.longestPalindrome("esbtzjaaijqkgmtaajpsdfiqtvxsgfvijpxrvxgfumsuprzlyvhclgkhccmcnquukivlpnjlfteljvykbddtrpmxzcrdqinsnlsteonhcegtkoszzonkwjevlasgjlcquzuhdmmkhfniozhuphcfkeobturbuoefhmtgcvhlsezvkpgfebbdbhiuwdcftenihseorykdguoqotqyscwymtjejpdzqepjkadtftzwebxwyuqwyeegwxhroaaymusddwnjkvsvrwwsmolmidoybsotaqufhepinkkxicvzrgbgsarmizugbvtzfxghkhthzpuetufqvigmyhmlsgfaaqmmlblxbqxpluhaawqkdluwfirfngbhdkjjyfsxglsnakskcbsyafqpwmwmoxjwlhjduayqyzmpkmrjhbqyhongfdxmuwaqgjkcpatgbrqdllbzodnrifvhcfvgbixbwywanivsdjnbrgskyifgvksadvgzzzuogzcukskjxbohofdimkmyqypyuexypwnjlrfpbtkqyngvxjcwvngmilgwbpcsseoywetatfjijsbcekaixvqreelnlmdonknmxerjjhvmqiztsgjkijjtcyetuygqgsikxctvpxrqtuhxreidhwcklkkjayvqdzqqapgdqaapefzjfngdvjsiiivnkfimqkkucltgavwlakcfyhnpgmqxgfyjziliyqhugphhjtlllgtlcsibfdktzhcfuallqlonbsgyyvvyarvaxmchtyrtkgekkmhejwvsuumhcfcyncgeqtltfmhtlsfswaqpmwpjwgvksvazhwyrzwhyjjdbphhjcmurdcgtbvpkhbkpirhysrpcrntetacyfvgjivhaxgpqhbjahruuejdmaghoaquhiafjqaionbrjbjksxaezosxqmncejjptcksnoq") << endl;
//
//	system("pause");
//}