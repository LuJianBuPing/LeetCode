#include "LeetCode.h"


// Definition for an interval.
 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };


class Solution {
public:
	vector<Interval> merge(vector<Interval> &intervals) {
		sort(intervals.begin(), intervals.end(), 
			[](const Interval& a, const Interval& b){
			return a.start<b.start; 
		});

		for (int i = 0; i < (int)intervals.size() - 1; ++i)
		{
			if (intervals[i].end >= intervals[i + 1].start)
			{
				intervals[i + 1].start = intervals[i].start;
				intervals[i + 1].end = max(intervals[i].end, intervals[i+1].end);

				intervals[i] = Interval(1,0);
			}
		}

		vector<Interval> result;
		for (int i = 0; i < intervals.size(); ++i)
			if (intervals[i].start <= intervals[i].end)
				result.push_back(intervals[i]);

		return std::move(result);
	}
};


int main()
{
	vector<Interval> inter;// = { { 1, 3 }, { 8, 10 }, { 2, 6 }, { 15, 18 } };
	Solution sl;

	auto result = sl.merge(inter);

	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i].start << "," << result[i].end << endl;
	}

	PAUSE;
}