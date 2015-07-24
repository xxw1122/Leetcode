class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        long long low = 1, high = x, res = x;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (mid * mid <= res && (mid + 1) * (mid + 1) > res) return mid;
            else if (mid * mid > res) high = mid - 1;
            else low = mid + 1;
        }
    }
};