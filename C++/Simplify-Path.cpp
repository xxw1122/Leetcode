class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        string cur;
        for (int i = 0; i < path.size(); i ++) {
            if (path[i] == '/') {
                if (cur == "..") {
                    if (!stk.empty()) stk.pop();                
                } else if (cur != "." && cur != "") {
                    stk.push(cur);
                }
                cur = "";
            } else {
                cur += path[i];
            }
        }
        if (cur == "..") {
            if (!stk.empty()) stk.pop();                
        } else if (cur != "." && cur != "") {
            stk.push(cur);
        }
        if (stk.empty()) return "/";
        cur = "";
        stack<string> stk1;
        while (!stk.empty()) {
            stk1.push(stk.top());
            stk.pop();
        }
        while (!stk1.empty()) {
            cur += "/";
            cur += stk1.top();
            stk1.pop();
        }
        return cur;
    }
};