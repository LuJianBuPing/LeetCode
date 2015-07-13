#include "LeetCode.h"

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int curgas = 0, mingas = 0, minnode = 0, N = gas.size();
		for (int i = 0; i<N; ++i)
		{
			if (curgas<mingas)
			{
				mingas = curgas;
				minnode = i;
			}
			curgas += gas[i] - cost[i];
		}

		curgas = 0;
		for (int i = 0; i<N; ++i)
		{
			int node = (minnode + i) % N;

			curgas += gas[node] - cost[node];
			if (curgas<0)
				return -1;
		}

		return minnode;
	}
};