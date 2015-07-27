class Solution {
public:
    /**
     * @param dividend the dividend
     * @param divisor the divisor
     * @return the result
     */
    int divide(int dividend, int divisor) {
        // Write your code here
        int symbol = 1;
        long long dvd = dividend, dvr = divisor, res = 0;
        if (!((dividend >= 0 && divisor >= 0) ||
                (dividend < 0 && divisor < 0))) symbol = -1;
        if (dvd < 0) dvd = -dvd;
        if (dvr <  0) dvr = -dvr;
        while (dvd >= dvr) {
            long long cnt = dvr, num = 1;
            while ((cnt << 1) <= dvd) {
                cnt = cnt << 1;
                num = num << 1;
            }
            dvd -= cnt;
            res += num;
        }
        res = res * symbol;
        if (res > INT_MAX || res < INT_MIN) return INT_MAX;
        return res;
    }
};
