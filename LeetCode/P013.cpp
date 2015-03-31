#include<iostream>
using namespace std;

int value[96] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
100, 500, 0, 0, 0, 0, 1, 0, 0, 50, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 10, 0, 0, 0, 0, 0, 0, 0 };

class Solution {
public:
	int romanToInt(string s) {
		int result = value[s[s.length() - 1]];
		for (int i = 0; i < s.length() - 1; ++i)
		{
			if (value[s[i]] < value[s[i + 1]])
				result -= value[s[i]];
			else
				result += value[s[i]];
		}
		return result;
	}
};

//int main()
//{
//	//int value[256];
//	//memset(value, 0, sizeof(value));
//	//value['I'] = 1;
//	//value['V'] = 5;
//	//value['X'] = 10;
//	//value['L'] = 50;
//	//value['C'] = 100;
//	//value['D'] = 500;
//	//value['M'] = 1000;
//
//	//for (int i = 0; i < 96; ++i)
//	//	cout << value[i] << ",";
//
//	Solution sl;
//	cout << sl.romanToInt("MCMXCIX") << endl;
//	system("pause");
//}