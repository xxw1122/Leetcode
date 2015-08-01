class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0, cur = 1;
        for (uint32_t i = 0; i < 32; i ++) {
            cur = (n >> i) & 1;
            res = res | (cur << (31 - i));
        }
        return res;
    }
};

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t x, y, pos, cnt;
        x = 1, y = 0, pos = 0, cnt = 1 << 31;
        while (x) {
            if (x & n) {
                y = y | (cnt >> pos);
            }
            pos ++;
            x = x << 1;
        }
        return y;
    }
};