#include "LeetCode.h"

class Solution {

public:
	bool isMatch(const char *s, const char *p) {
		int lens = strlen(s), lenp = strlen(p);
		if (lenp == 0)
			return (lens==0);
		bool startx = (p[0] == '*'), endx = (p[lenp - 1] == '*');
		vector<string> parts;
		vector<bool> hasqm;

		string tmpstr;
		bool tmpqm = false;
		for (int i = 0; i <= lenp; ++i)
		{
			if (p[i] == '*'||p[i] == 0)
			{
				if (tmpstr.length() != 0)
				{
					parts.push_back(tmpstr);
					hasqm.push_back(tmpqm);
					tmpstr.clear();
					tmpqm = false;
				}
			}
			else
			{
				tmpstr.push_back(p[i]);
				if (p[i] == '?')
					tmpqm = true;
			}
		}


		int j = 0;
		for (int i = 0; i < parts.size(); ++i)
		{
			const char* find = hasqm[i] ? indexOf(s + j, parts[i].c_str()) : strstr(s + j, parts[i].c_str());
			if (find == NULL)
				return false;
			if (i == 0 && !startx && (find != s || parts.size()==1 && parts[0].length()!=lens && !endx))
				return false;
			if (i + 1 == parts.size() && !endx)
			{
				j = lens - parts[i].length();
				if (j<0 || NULL == (hasqm[i] ? indexOf(s + j, parts[i].c_str()) : strstr(s + j, parts[i].c_str())))
					return false;
			}
			j = (find-s) + parts[i].length();
		}

		return true;
	}

	const char* indexOf(const char* s, const char* p)
	{
		for (const char* si = s; *si != 0; ++si)
		{
			for (const char* sj = si, *pj = p;; ++sj, ++pj)
			{
				if (*sj == 0 || *pj == 0)
				{
					if (*pj == 0)
						return si;
					else
						break;
				}

				if (*pj != '?'&&*pj != *sj)
					break;
			}
		}
		return NULL;
	}
};

//int main()
//{
//	Solution sl;
//
//	cout << sl.indexOf("aa", "a") << endl;
//	cout << sl.indexOf("aaabc", "abc") << endl;
//	cout << sl.indexOf("aabcd", "a?c") << endl;
//
//	cout << sl.isMatch("aa", "a") << endl;
//	cout << sl.isMatch("aa", "aa") << endl;
//	cout << sl.isMatch("aaa", "aa") << endl;
//	cout << sl.isMatch("aa", "*") << endl;
//	cout << sl.isMatch("aa", "a*") << endl;
//	cout << sl.isMatch("ab", "?*") << endl;
//	cout << sl.isMatch("aab", "c*a*b") << endl;
//	cout << sl.isMatch("aaaa","*aaaa*") <<endl;
//	cout << sl.isMatch("babaaababaabababbbbbbaabaabbabababbaababbaaabbbaaab", "***bba**a*bbba**aab**b") << endl;
//
//	PAUSE;
//}