#include "LeetCode.h"

class Solution {
public:
	int candy(vector<int>& ratings) {
		vector<pair<int, int>> score2index;
		vector<int> num(ratings.size());
		for (int i = 0; i<ratings.size(); ++i)
			score2index.push_back(make_pair(ratings[i], i));

		sort(score2index.begin(), score2index.end(), [](const pair<int, int>& a, const pair<int, int>& b){return a.first<b.first; });

		for (auto& s2i : score2index)
		{
			int s = s2i.first;
			int i = s2i.second;

			num[i] = 1;
			if (i - 1 >= 0 && ratings[i - 1]<ratings[i] && num[i - 1] >= num[i])
				num[i] = num[i - 1] + 1;
			if (i + 1<ratings.size() && ratings[i + 1]<ratings[i] && num[i + 1] >= num[i])
				num[i] = num[i + 1] + 1;
		}

		return accumulate(num.begin(), num.end(), 0);
	}
};