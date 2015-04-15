#include "LeetCode.h"

class Solution {
public:
	vector<string> fullJustify(vector<string> &words, int L) {
		vector<string> result;

		int j = 0;
		for (int i = 0; i < words.size(); i = j)
		{
			int c = -1;
			int wordssize = 0;
			for (j = i; j < words.size(); ++j)
			{
				if (c + (words[j].length() + 1) <= L)
				{
					c += (words[j].length() + 1);
					wordssize += words[j].length();
				}
				else
					break;
			}

			string line = words[i];
			if (j == words.size() || j - i == 1)
			{
				for (int k = i + 1; k < j; ++k)
					line += " " + words[k];
				while (line.length() < L)
					line.push_back(' ');
			}
			else
			{
				int numspace = L - wordssize;
				int spacew = numspace / (j - i - 1);
				int remain = numspace - (spacew*(j - i - 1));

				string space(spacew, ' ');
				for (int k = i + 1; k < j; ++k)
				{
					line += space;
					if (k - i - 1 < remain)
						line.push_back(' ');
					line += words[k];
				}
			}
			result.push_back(line);
		}
		return std::move(result);
	}
};

//int main()
//{
//	Solution sl;
//
//	vector<string> words = { "This", "is", "an", "example", "of", "text", "justification." };
//	displayVector(sl.fullJustify(words,16));
//
//	PAUSE;
//}