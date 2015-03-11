class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        if (x <= 1) return x;
        long long left = 1, right = x, mid, cnt = x;
        while ( left <= right ) {
            mid = (right + left) / 2;
            if (mid * mid == cnt) return mid;
            else if (mid * mid < cnt && (mid + 1) * (mid + 1) > cnt) return mid;
            else if (mid * mid > cnt) right = mid - 1;
            else left = mid + 1;
        }
    }
};
