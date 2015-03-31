#include<iostream>
#include<string>
using namespace std;

string base[4][10] = { { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
{ "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },
{ "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" },
{ "", "M", "MM", "MMM"}
};
class Solution {
public:
	string intToRoman(int num) {
		string result;
		int i = 0;
		while (num > 0)
		{
			result = base[i++][num % 10]+result;
			num /= 10;
		}
		return result;
	}
};

//int main()
//{
//	Solution sl;
//	cout << sl.intToRoman(1999) << endl;
//	system("pause");
//}