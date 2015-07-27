# Definition for an interval.
class Interval:
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

class Solution:
    # @param intervals, a list of Intervals
    # @param newInterval, a Interval
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

    def insert(self, intervals, newInterval):
        intervals.sort(self.cmp1)
        seq = []
        index = -1
        for i in range(len(intervals)):
            if intervals[i].start > newInterval.end:
                index = i
                break
            elif newInterval.start > intervals[i].end:
                seq.append(intervals[i])
            else:
                newInterval.start = min(newInterval.start, intervals[i].start)
                newInterval.end = max(newInterval.end, intervals[i].end)
        seq.append(newInterval)
        if index != -1:
            seq += intervals[index:]
        return seq