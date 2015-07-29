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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int cur = 0;
        for (; cur < intervals.size(); cur ++) {
            if (intervals[cur].start > newInterval.end) {
                break;
            } else if (intervals[cur].end < newInterval.start) {
                res.push_back(intervals[cur]);
            } else {
                newInterval.start = min(newInterval.start, intervals[cur].start);
                newInterval.end = max(newInterval.end, intervals[cur].end);
            }
        }
        res.push_back(newInterval);
        for (; cur < intervals.size(); cur ++) {
            res.push_back(intervals[cur]);
        }
        return res;
    }
};