import copy

# Definition for an interval.
class Interval:
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

class Solution:
    # @param intervals, a list of Interval
    # @return a list of Interval
    def cmp1(self, x, y):
        if x.start < y.start:
            return -1
        elif x.start > y.start:
            return 1
        elif x.start == y.start:
            if x.end < y.end:
                return -1
            else:
                return 1

    def merge(self, intervals):
        if len(intervals) < 1:
            return []
        intervals.sort(self.cmp1)
        seq = []
        cnt = Interval(intervals[0].start, intervals[0].end)
        for i in range(1, len(intervals)):
            if cnt.end >= intervals[i].start:
                cnt.start = min(cnt.start, intervals[i].start)
                cnt.end = max(cnt.end, intervals[i].end)
            else:
                seq.append(copy.copy(cnt))
                cnt = copy.copy(intervals[i])
        seq.append(cnt)
        return seq