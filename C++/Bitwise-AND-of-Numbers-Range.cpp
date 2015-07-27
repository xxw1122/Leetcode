class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int p = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            p ++;
        }
        return m << p;
    }
};