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
    int minMeetingRooms(vector<Interval>& intervals) {
       vector<pair<int, bool> > v;
       for (auto &i : intervals) {
            v.push_back(make_pair(i.start, true));
            v.push_back(make_pair(i.end, false));
        }
        sort(v.begin(), v.end());
        int res = 0, cnt = 0;
        for (auto &i : v) {
        	if (!i.second) {
        		cnt --;
        	} else {
        		cnt ++;
        	}
        	res = max(res, cnt);
        }
        return res;
    }
};