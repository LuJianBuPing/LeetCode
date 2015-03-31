#include "LeetCode.h"

class Solution {
public:
	int jump(int A[], int n){
		if (n == 1)
			return 0;
		
		int step = 1;
		
		for (int pos = 0;pos+A[pos]<n-1;)
		{
			int m = -1, mi = pos;
			for (int j = pos + 1; j <= pos + A[pos]; ++j)
			{
				if (j + A[j] > m)
				{
					m = j + A[j];
					mi = j;
				}
			}
			pos = mi;
			++step;
		}
		return step;
	}

    int jump2(int A[], int n) {
		int f = 0;
		vector<int> d(n, INT_MIN);
		int sized = 1;
		d[0] = -(n - 1);
		for (int i = n - 2; i >= 0; --i)
		{
			int fast = i + A[i];

			int  j = lower_bound(d.begin(), d.begin() + sized, -fast) - d.begin();

			if (j >= 0 && j < sized)
			{
				f = j + 1;
				if (-i > d[f])
				{
					d[f] = -i;
					sized = f + 1;
				}
			}
		}
		return f;
    }
};

//int main()
//{
//	Solution sl;
//	//int A[] = { 2, 3, 1, 1, 4 };
//
//	//int A[] = { 1, 1, 1, 1 };
//	int A[] = { 8, 4, 3, 4, 0, 0, 9, 7, 2, 3, 5, 7, 3, 1, 1, 5, 1, 8, 6, 1, 1, 6, 1, 1, 8, 0, 4 };
//
//	cout << sl.jump(A, sizeof(A) / sizeof(int)) << endl;
//
//	PAUSE;
//}