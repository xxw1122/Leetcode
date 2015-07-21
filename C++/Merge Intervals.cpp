#include <vector>
#include <algorithm>

/**
 * Definition of Interval:
 */
class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    static bool cmp(Interval x, Interval y) {
        return x.start < y.start;
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> res;
        if (intervals.empty()) return res;
        Interval pre = intervals[0];
        for (int i = 1; i < intervals.size(); i ++) {
            if (intervals[i].start > pre.end) {
                res.push_back(pre);
                pre = intervals[i];
            } else {
                pre.end = max(pre.end, intervals[i].end);
            }
        }
        res.push_back(pre);
        return res;
    }
};
