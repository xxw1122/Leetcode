# Definition for a point
# class Point:
#     def __init__(self, a=0, b=0):
#         self.x = a
#         self.y = b

class Solution:
    # @param points, a list of Points
    # @return an integer
    def maxPoints(self, points):
        length = len(points)
        if length < 3: return length
        res = -1
        for i in range(length):
            slope = {'inf': 0}
            samePointsNum = 1
            for j in range(length):
                if i == j:
                    continue
                elif points[i].x == points[j].x and points[i].y != points[j].y:
                    slope['inf'] += 1
                elif points[i].x != points[j].x:
                    k = 1.0 * (points[i].y - points[j].y) / (points[i].x - points[j].x)
                    if k not in slope:
                        slope[k] = 1
                    else:
                        slope[k] += 1
                else:
                    samePointsNum += 1
            res = max(res, max(slope.values()) + samePointsNum)
        return res