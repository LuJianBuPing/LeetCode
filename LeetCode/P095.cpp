#include "LeetCode.h"

class Solution {
	vector<TreeNode*> innerTrees[16][16];
public:
	vector<TreeNode *> generateTrees(int n) {
		for (int i = 0; i <= n; ++i)
		{
			innerTrees[i][0].push_back(NULL);
			innerTrees[i][1].push_back(new TreeNode(i+1));
		}

		for (int len = 2; len <= n; ++len)
		{
			for (int i = 0; i <=n - len; ++i)
			{
				for (int j = 0; j < len; ++j)
				{
					int k = i + j;
					vector<TreeNode*>& left = innerTrees[i][k - i];
					vector<TreeNode*>& right = innerTrees[k + 1][len - j - 1];

					//cout << len << ",i&j:" << i << "," << j <<",len-j-1:"<<len-j-1<< "," << left.size() << "," << right.size() << endl;

					for (int l = 0; l < left.size(); ++l)
					{
						for (int r = 0; r < right.size(); ++r)
						{
							TreeNode* node = new TreeNode(k+1);
							node->left = left[l];
							node->right = right[r];
							innerTrees[i][len].push_back(node);
						}
					}
				}
			}
		}

		return innerTrees[0][n];
	}
};

class Solution2 {
	vector<int> A;
public:
	vector<TreeNode *> generateTrees(int n) {
		for (int i = 1; i <= n; ++i)
			A.push_back(i);
		return generate(0, n);
	}

	vector<TreeNode *> generate(int i, int len){
		if (len == 0)
			return vector<TreeNode*>({ (TreeNode*)NULL });
		else if (len == 1)
			return vector<TreeNode*>({new TreeNode(A[i])});

		vector<TreeNode*> result;

		for (int j = 0; j < len; ++j)
		{
			int k = i + j;
			vector<TreeNode*> left = generate(i, k - i);
			vector<TreeNode*> right = generate(k + 1, len - j - 1);

			for (int l = 0; l < left.size(); ++l)
			{
				for (int r = 0; r < right.size(); ++r)
				{
					TreeNode* node = new TreeNode(A[k]);
					node->left = left[l];
					node->right = right[r];
					result.push_back(node);
				}
			}
		}
		return result;
	}
};

//int main()
//{
//	Solution sl;
//
//	cout << sl.generateTrees(9).size() << endl;
//
//	PAUSE;
//}
//
