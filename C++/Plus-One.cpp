class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int d = 1;
        for (int i = digits.size() - 1; i >= 0; i --) {
            int temp = digits[i] + d;
            digits[i] = temp % 10;
            d = temp / 10;
        }
        if (d != 0) {
            digits.insert(digits.begin(), d);
        }
        return digits;
    }
};