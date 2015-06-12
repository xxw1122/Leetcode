#include <string>
#include <stack>

class Solution {
public:
    int Opcal(char Op, int x, int y) {
        if (Op == '+') return x + y;
        else if (Op == '-') return y - x;
    }
    int calculate(string s) {
        stack<char> OpStk;
        stack<int> IntStk;
        int num = 0, tag = 0;
        for (int i = 0; i < s.size(); i ++) {
            if (s[i] >= '0' && s[i] <= '9') {
                tag = 1;
                num = num * 10 + s[i] - '0';
            } else {
                if (tag) {
                    IntStk.push(num);
                    num = 0;
                    tag = 0;
                }
                if (s[i] == ' ') continue;
                if (s[i] != ')') {
                    if (s[i] == '(') OpStk.push(s[i]);
                    else {
                        while (!OpStk.empty() && OpStk.top() != '(') {
                            int x = IntStk.top();
                            IntStk.pop();
                            int y = IntStk.top();
                            IntStk.pop();
                            int temp = Opcal(OpStk.top(), x, y);
                            IntStk.push(temp);
                            OpStk.pop();
                        }
                        OpStk.push(s[i]);
                    }
                } else {
                    while (OpStk.top() != '(') {
                        int x = IntStk.top();
                        IntStk.pop();
                        int y = IntStk.top();
                        IntStk.pop();
                        int temp = Opcal(OpStk.top(), x, y);
                        IntStk.push(temp);
                        OpStk.pop();
                    }
                    OpStk.pop();
                }
            }
        }
        if (tag == 1) {
            IntStk.push(num);
        }
        while (!OpStk.empty()) {
            int x = IntStk.top();
            IntStk.pop();
            int y = IntStk.top();
            IntStk.pop();
            int temp = Opcal(OpStk.top(), x, y);
            IntStk.push(temp);
            OpStk.pop();
        }
        return IntStk.top();
    }
};