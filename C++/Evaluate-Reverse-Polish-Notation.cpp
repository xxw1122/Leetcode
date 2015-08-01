class Solution {
public:
    bool isop(const string &str) {
        if (str == "+" || str == "-" || str == "/" || str == "*") return true;
        return false;
    }
    int helper(int a, int b, const string &op) {
        if (op == "+") return a + b;
        else if (op == "*") return a * b;
        else if (op == "-") return b - a;
        else return b / a;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (int i = 0; i < tokens.size(); i ++) {
            if (isop(tokens[i])) {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push(helper(a, b, tokens[i]));
            } else {
                stk.push(stoi(tokens[i]));
            }
        }
        return stk.top();
    }
};