class Solution {
public:
    int convert(int n) {
        int res = 0;
        while (n != 0) {
            int temp = n % 10;
            res += temp * temp;
            n = n / 10;
        }
        return res;
    }
    bool isHappy(int n) {
        set<int> hash;
        hash.insert(n);
        while (n != 1) {
            int cur = convert(n);
            if (hash.find(cur) != hash.end()) return false;
            hash.insert(cur);
            n = cur;
        }
        return true;
    }
};