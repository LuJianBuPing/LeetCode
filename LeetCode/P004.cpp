#include<iostream>
#include<algorithm>
using namespace::std;

class Solution {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		if ((m+n)%2==1)
			return findKthItem(A, m, B, n, (m + n + 1)/2);
		else
		{
			double m1 = findKthItem(A, m, B, n, (m + n) / 2);
			double m2 = findKthItem(A, m, B, n, 1 + (m + n) / 2);
			return (m1 + m2) / 2;
		}
	}

	double findKthItem(int* A, int m, int* B, int n, int k)
	{
		while (true)
		{
			if (m == 0)
				return B[k - 1];
			if (n == 0)
				return A[k - 1];

			int p1 = m / 2, p2 = n / 2;

			if (A[p1] > B[p2])
			{
				swap(A, B);
				swap(m, n);
				swap(p1, p2);
			}

			int startA = 0, endB = n;

			if (p1 + 1 + p2 < k)
				startA = p1 + 1;
			//p1 + 1 + p2 >= k
			else{
				if (p1 + 1 + p2 == k)
					startA = p1;
				endB = p2;
			}
				


			A += startA;
			m -= startA;
			//B=B;
			n = endB;
			k -= startA;
		}
	}
};

//int main()
//{
//	Solution sl;
//	int A[] = { 2, 4, 6, 8};
//	int B[] = { 3, 5, 7, 9, 11};
//
//	cout << sl.findMedianSortedArrays(A, 4, B, 4) <<endl;
//
//	system("pause");
//}