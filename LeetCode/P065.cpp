#include "LeetCode.h"

#include <regex>
class Solution {
public:
	bool isNumber(string s) {
		
		regex partten(" *[+-]?((([0-9]+)(\\.)?([0-9]*))|(\\.[0-9]+))((e|E)([+-]?([0-9]+)))? *");

		return regex_match(s, partten);
	}
};
//
//int main()
//{
//	Solution sl;
//
//	cout << sl.isNumber("0") << endl;
//	cout << sl.isNumber("01") << endl;
//	cout << sl.isNumber("234") << endl;
//	cout << sl.isNumber("234.") << endl;
//	cout << sl.isNumber("234.12321") << endl;
//	cout << sl.isNumber("234.12321E21") << endl;
//
//	PAUSE;
//}