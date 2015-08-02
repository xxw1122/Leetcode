class Solution {
public:
    bool isdigit(char ch) {
        if (ch >= '0' && ch <= '9') return true;
        return false;
    }
    int helper(char ch, int x, int y) {
        if (ch == '-') return y - x;
        else if (ch == '+') return x + y;
    }
    void solve(stack<char>& OpStk, stack<int>& IntStk) {
        char cur = OpStk.top();
        OpStk.pop();
        int x = IntStk.top();
        IntStk.pop();
        int y = IntStk.top();
        IntStk.pop();
        IntStk.push(helper(cur, x, y));
    }
    int calculate(string s) {
        stack<char> OpStk;
        stack<int> IntStk;
        int flag = 0;
        string str = "";
        for (int i = 0; i < s.size(); i ++) {
            if (isdigit(s[i])) {
                str += s[i];
                flag = 1;
            } else {
                if(flag == 1) IntStk.push(stoi(str));
                flag = 0;
                str = "";
                if (s[i] == '(') {
                    OpStk.push(s[i]);
                } else if (s[i] == ')') {
                    while (OpStk.top() != '(') {
                        solve(OpStk, IntStk);
                    }
                    OpStk.pop();
                } else if (s[i] != ' ') {
                    while (!OpStk.empty() && OpStk.top() != '(') {
                        solve(OpStk, IntStk);
                    }
                    OpStk.push(s[i]);
                }
            }
        }
        if (flag == 1) IntStk.push(stoi(str));
        while (!OpStk.empty()) {
            solve(OpStk, IntStk);
        }
        return IntStk.top();
    }
};

