#include "LeetCode.h"

class Solution {
	vector<string> words;
	vector<bool> visited;
	vector<int> dist;
	vector<int> sol;
	vector<vector<int>> path;
	vector<vector<int>> links;
	vector<vector<string>> result;
	unordered_map<string, vector<int>> poss;
public:
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		words.push_back(start);
		for (auto& str : dict)
			words.push_back(str);
		words.push_back(end);

		make_links();
		visited = vector<bool>(words.size());
		path = vector<vector<int>>(words.size());
		dist = vector<int>(words.size(), INT_MAX);
		visited[0] = true;
		dist[0] = 0;

		bfs(0, words.size() - 1);
		find_results(words.size() - 1);
		return result;
	}

	void bfs(int start, int end)
	{
		queue<int> qq;
		qq.push(start);

		while (!qq.empty())
		{
			int v = qq.front();
			qq.pop();

			if (v == end)
				break;

			for (int i : links[v])
			{
				int d = dist[v] + 1;

				if (dist[i] < d) continue;
				else
					if (dist[i] == d)
					{
					path[i].push_back(v);
					continue;
					}
				dist[i] = d;
				qq.push(i);
				path[i].push_back(v);
			}
		}
	}

	void find_results(int v)
	{
		if (v == 0)
		{
			vector<string> sol2;
			sol2.push_back(words[0]);
			for (auto it = sol.rbegin(); it != sol.rend(); ++it)
			{
				sol2.push_back(words[*it]);
			}
			result.push_back(sol2);
		}
		sol.push_back(v);
		for (int i : path[v])
			find_results(i);
		sol.pop_back();
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