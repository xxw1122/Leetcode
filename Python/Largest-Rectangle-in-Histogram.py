class Solution:
    # @param height, a list of integer
    # @return an integer
    def largestRectangleArea(self, height):
        seq = []
        cnt = 0
        height.append(0)
        i = 0
        while i < len(height):
            if len(seq) == 0 or height[i] >= height[seq[-1]]:
                seq.append(i)
                i += 1
            else:
                t = seq.pop()
                if len(seq) == 0:
                    cnt = max(cnt, height[t] * i)
                else:
                    cnt = max(cnt, height[t] * (i - seq[-1] - 1))
        return cnt