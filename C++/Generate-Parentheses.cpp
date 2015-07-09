class Solution {
public:
    void helper(vector<string> &res, string str, int x, int y, int n) {
        if (y == n) {
            res.push_back(str);
            return;
        }
        if (x == n) {
            string str1 = str + ")";
            helper(res, str1, x, y + 1, n);
        } else {
            string str1 = str + "(";
            helper(res, str1, x + 1, y, n);
            if (x > y) {
                str1 = str + ")";
                helper(res, str1, x, y + 1, n);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res, "", 0, 0, n);
        return res;
    }
};