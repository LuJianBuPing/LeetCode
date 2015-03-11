#include<iostream>
#include<string>
#include<vector>
using namespace std;

string numstr[] = { "","", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		if (digits.length() == 0)
			return vector<string>();
		vector<string> result = {""};
		for (char dgt : digits)
		{
			vector<string> next;
			for (const string& s : result)
			{
				for (char ch : numstr[dgt - '0'])
				{
					next.push_back(s+ch);
				}
			}
			result = std::move(next);
		}
		return result;
	}
};
//
//int main()
//{
//	Solution sl;
//	for (const string&s : sl.letterCombinations("23"))
//	{
//		cout << s << " ";
//	}
//	system("pause");
//}