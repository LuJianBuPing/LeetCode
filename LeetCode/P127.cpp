#include "LeetCode.h"

class Solution {
	vector<string> words;
	vector<int> dist;
	vector<vector<int>> links;
	unordered_map<string, vector<int>> poss;
public:
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		words.push_back(start);
		for (auto& str : dict)
			words.push_back(str);
		words.push_back(end);

		make_links();

		dist = vector<int>(words.size(), INT_MAX);
		dist[0] = 0;

		return bfs(0, words.size() - 1);;
	}

	int bfs(int start, int end)
	{
		queue<int> qq;
		qq.push(start);

		while (!qq.empty())
		{
			int v = qq.front();
			qq.pop();

			for (int i : links[v])
			{
				int d = dist[v] + 1;
				if (dist[i] <= d) continue;
				dist[i] = d;
				qq.push(i);
				if (i == end)
					break;
			}
		}

		return dist[end] == INT_MAX ? 0 : dist[end] + 1;
	}

	void make_links()
	{
		links = vector<vector<int>>(words.size());

		for (int i = 0; i < words.size(); ++i)
		{
			for (int j = 0; j < words[i].length(); ++j)
			{
				string str = words[i];
				str[j] = '*';
				poss[str].push_back(i);
			}
		}

		for (int i = 0; i < words.size(); ++i)
		{
			for (int j = 0; j < words[i].length(); ++j)
			{
				string str = words[i];
				str[j] = '*';
				for (int k : poss[str])
				{
					if (can_link(words[i], words[k]))
						links[i].push_back(k);
				}
			}
		}
	}

	bool can_link(string& a, string& b)
	{
		if (a.length() != b.length())
			return false;

		int diff = 0;

		for (int i = 0; i < a.length(); ++i)
			if (a[i] != b[i])
				++diff;
		return diff == 1;
	}
};