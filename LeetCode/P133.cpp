#include "LeetCode.h"

struct UndirectedGraphNode {
     int label;
     vector<UndirectedGraphNode *> neighbors;
     UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> visited;
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == NULL)
			return NULL;
		if (visited.find(node) != visited.end())
			return visited[node];

		auto copynode = new UndirectedGraphNode(node->label);
		visited[node] = copynode;

		for (auto p : node->neighbors)
			copynode->neighbors.push_back(cloneGraph(p));

		return copynode;
	}
};