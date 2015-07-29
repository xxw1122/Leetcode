/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool cmp(Interval x, Interval y) {
        return x.start < y.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
    	if (intervals.size() <= 1) return intervals;
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> res;
        Interval pre(intervals[0].start, intervals[0].end);
        for (int i = 1; i < intervals.size(); i ++) {
        	if (intervals[i].start > pre.end) {
        		res.push_back(pre);
        		pre = intervals[i];
        	} else {
        		pre.end = max(intervals[i].end, pre.end);
        	}
        }
        res.push_back(pre);
        return res;
    }
};