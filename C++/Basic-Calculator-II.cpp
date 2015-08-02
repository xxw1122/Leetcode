class Solution {
public:
    int Opcal(char Op, int x, int y) {
        if (Op == '+') return x + y;
        else if (Op == '-') return y - x;
        else if (Op == '*') return x * y;
        else return y / x;
    }
    int pre(char ch) {
        if (ch == '*' || ch == '/') return 2;
        else return 1;
    }
    int calculate(string s) {
        stack<int> stk1;
        stack<char> stk2;
        int num = 0, tag = 0;
        for (int i = 0; i < s.size(); i ++) {
            if (s[i] >= '0' && s[i] <= '9') {
                tag = 1;
                num = num * 10 + s[i] - '0';
            } else {
                if (tag == 1) {
                    stk1.push(num);
                    tag = 0;
                    num = 0;
                }
                if (s[i] == ' ') continue;
                while (!stk2.empty() && pre(stk2.top()) >= pre(s[i])) {
                    int x = stk1.top();
                    stk1.pop();
                    int y = stk1.top();
                    stk1.pop();
                    char ch = stk2.top();
                    stk2.pop();
                    int temp = Opcal(ch, x, y);
                    stk1.push(temp);
                }
                stk2.push(s[i]);
            }
        }
        if (tag == 1) {
            stk1.push(num);
        }
        while (!stk2.empty()) {
            int x = stk1.top();
            stk1.pop();
            int y = stk1.top();
            stk1.pop();
            char ch = stk2.top();
            stk2.pop();
            int temp = Opcal(ch, x, y);
            stk1.push(temp);
        }
        return stk1.top();
    }
};