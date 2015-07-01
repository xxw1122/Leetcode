class Solution {
public:
    int reverse(int x) {
        int symbol = 1;
        if (x < 0) {
            symbol = -1;
            x = -x;
        }
        string s = std::to_string(x);
        std::reverse(s.begin(), s.end());
        int sum = 0;
        for (int i = 0; i < s.size(); i ++) {
            if (symbol == 1 && ((sum > INT_MAX / 10) || (sum == INT_MAX / 10 &&  s[i] - '0' > 7)) return 0;
            else if(symbol == -1 && ((sum > INT_MAX / 10) || (sum == INT_MAX / 10 && s[i] - '0' > 8)) return 0;
            sum = sum * 10 + s[i] - '0';
        }
        return sum * symbol;
    }
};