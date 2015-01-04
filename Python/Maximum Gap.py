class Solution:
    # @param num, a list of integer
    # @return an integer
    def maximumGap(self, num):
        N = len(num)
        if N < 2:
            return 0
        A = min(num)
        B = max(num)
        bucketRange = max(1, int((B - A - 1) / (N - 1)) + 1) #ceil( (B - A) / (N - 1) )
        bucketLen = (B - A) / bucketRange + 1
        buckets = [None] * bucketLen
        for K in num:
            loc = (K - A) / bucketRange
            bucket = buckets[loc]
            if bucket is None:
                bucket = {'min' : K, 'max' : K}
                buckets[loc] = bucket
            else:
                bucket['min'] = min(bucket['min'], K)
                bucket['max'] = max(bucket['max'], K)
        maxGap = 0
        for x in range(bucketLen):
            if buckets[x] is None:
                continue
            y = x + 1
            while y < bucketLen and buckets[y] is None:
                y += 1
            if y < bucketLen:
                maxGap = max(maxGap, buckets[y]['min'] - buckets[x]['max'])
            x = y
        return maxGap