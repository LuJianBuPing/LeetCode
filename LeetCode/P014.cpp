#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
		string result;
		for (int i = 0;; ++i)
		{
			char ch;
			if (strs.size()==0 || strs[0].length() <= i)
				break;
			else
				ch = strs[0][i];
			bool end = false;
			for (const string& s : strs)
			{
				if (s.length() <= i || ch != s[i])
				{
					end = true;
					break;
				}
			}
			if (end)
				break;
			else
				result.push_back(ch);
		}
		return result;
    }
};


//int main()
//{
//	vector<string> data = {"123","125","12345"};
//	Solution sl;
//	cout << sl.longestCommonPrefix(data) << endl;
//
//	system("pause");
//}