class Solution {
public:
    /**
     * @param n the nth
     * @return the nth sequence
     */
    string solve(const string &str) {
        int num = 1;
        char ch = str[0];
        string st = "";
        for (int i = 1; i < str.length(); i ++) {
            if (str[i] == ch) {
                num ++;
            } else {
                st += to_string(num);
                st += str[i-1];
                num = 1;
                ch = str[i];
            }
        }
        st += to_string(num);
        st += str.back();
        return st;
    }
    string countAndSay(int n) {
        // Write your code here
        string str = "1";
        while (n > 1) {
            string st = solve(str);
            str = st;
            n -= 1;
        }
        return str;
    }
};
