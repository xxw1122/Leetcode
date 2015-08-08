class Solution {
public:
    int longestValidParentheses(string s) {
        int maxlen = 0, last = -1;
        stack<int> st;
        for(int i = 0; i < s.size(); i ++){
            if(s[i] == '(') st.push(i);
            else{
                if(st.empty()) last = i;
                else{
                    st.pop();
                    if(st.empty()) maxlen = max(maxlen, i - last);
                    else maxlen = max(maxlen, i - st.top());
                }
            }
        }
        return maxlen;
    }
};