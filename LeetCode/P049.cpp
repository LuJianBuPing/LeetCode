#include "LeetCode.h"

class Solution {
public:
	vector<string> anagrams(vector<string> &strs) {
		vector<string> result;
		map<vector<int>,string> fpmap;

		for (const auto& str : strs)
		{
			auto fp = fingerPrint(str);
			auto it = fpmap.find(fp);
			if (it != fpmap.end())
			{
				if (it->second!="*")
				{
					result.push_back(it->second);
					it->second = "*";
				}
				result.push_back(str);
			}
			else
				fpmap[fp] = str;
		}

		return result;
	}

	vector<int> fingerPrint(const string& str)
	{
		vector<int> fp(26, 0);
		for (auto ch : str)
		{
			fp[ch - 'a']++;
		}
		return std::move(fp);
	}
};

int main()
{
	Solution sl;
	
	displayVector(sl.anagrams(vector<string>({"ant","ant","ant","",""})));


	PAUSE;
}