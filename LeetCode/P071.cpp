#include "LeetCode.h"

class Solution {
public:
	string simplifyPath(string path) {
		path.push_back('/');
		vector<string> names;
		string name;

		for (int i = 0; i < path.length(); ++i)
		{
			if (path[i] == '/')
			{
				if (name.length()>0 && name != ".")
				{
					if (name == "..")
					{
						if (names.size() > 0)
							names.pop_back();
					}
					else
					{
						names.push_back(name);
					}
				}
				name.clear();
			}
			else
				name.push_back(path[i]);
		}

		string result = "/";

		for (int i = 0; i < names.size(); ++i)
		{
			if (i != 0)
				result.push_back('/');
			result += names[i];
		}

		return result;
	}
};

//int main()
//{
//	Solution sl;
//
//	cout << sl.simplifyPath("/...") << endl;;
//
//	PAUSE;
//}