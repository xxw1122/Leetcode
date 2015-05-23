#include <string>
#include <algorithm>

class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int reverse(int n) {
        // Write your code here
        int symbol = 1, val = 0;
        if (n < 0) {
            n = -n;
            symbol = -1;
        }
        string str = std::to_string(n);
        std::reverse(str.begin(), str.end());
        if (str.size() >= 11) return 0;
        for (int i = 0; i < str.size(); i ++) {
            if (symbol > 0 && (val > INT_MAX / 10 || (val == INT_MAX / 10 && i + 1 < str.size() && str[i+1] > '7'))) return 0;
            else if (symbol < 0 && (val > INT_MAX / 10 || (val == INT_MAX / 10 && i + 1 < str.size() && str[i+1] > '8'))) return 0;
            val = val * 10 + str[i] - '0';
        }
        return val * symbol;
    }
};
