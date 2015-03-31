#include<iostream>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		int radix1 = 1, radix2 = 1;
		while (x / 10 >= radix1)
			radix1 *= 10;

		for (; radix1 > radix2; radix1 /= 10, radix2 *= 10)
			if ((x / radix1) % 10 != (x / radix2) % 10)
				return false;
		return true;
	}
};

//int main()
//{
//	Solution sl;
//	cout << sl.isPalindrome(123) << endl;
//	cout << sl.isPalindrome(12321) << endl;
//	cout << sl.isPalindrome(1234554321) << endl;
//	system("pause");
//}