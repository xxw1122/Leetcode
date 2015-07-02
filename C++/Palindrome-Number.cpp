class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int cur = 0, cnt = x;
        while (cnt != 0) {
            cur = cur * 10 + cnt % 10;
            cnt = cnt / 10;
        }
        return x == cur;
    }
};