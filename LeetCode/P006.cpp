#include<string>
#include<iostream>
#include<vector>
#include<list>

using namespace std;

class Solution {
public:
	string convert1(string s, int nRows) {
		if (nRows == 1) return s;

		vector<list<char>> rows(nRows);
		int y = 0, dy = 1;
		
		for (char ch : s)
		{
			rows[y].push_back(ch);
			if (y == 0)
				dy = 1;
			else if (y + 1 == nRows)
				dy = -1;
			y += dy;
		}

		int i = 0;
		for (list<char>& chlist : rows)
			for (char ch : chlist)
				s[i++] = ch;
		return s;
	}

	string convert(string s, int nRows) {
		if (nRows == 1) return s;

		string result;
		int gap = nRows * 2 - 2;
		for (int i = 0; i < nRows; ++i)
		{


			if (i == 0 || (i + 1) == nRows)
			{
				for (int p = i; p < s.length();p+=gap)
					result.push_back(s[p]);
			}
			else
			{
				for (int p1 = i, p2 = gap - i; p1 < s.length();p1+=gap,p2+=gap)
				{
					result.push_back(s[p1]);
					if (p2 < s.length())
						result.push_back(s[p2]);
				}
			}
		}
		
		return result;
	}
};
//
//int main()
//{
//	Solution sl;
//	cout << sl.convert("PAYPALISHIRING", 1) << endl;
//	cout << sl.convert("PAYPALISHIRING", 2) << endl;
//	cout << sl.convert("PAYPALISHIRING", 3) << endl;
//	cout << sl.convert("PAYPALISHIRING", 4) << endl;
//	cout << sl.convert("PAYPALISHIRING", 100) << endl;
//	system("pause");
//}