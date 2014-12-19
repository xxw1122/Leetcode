class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> st;
        for(int i = 0; i < num.size(); i++){
            if(st.find(num[i]) == st.end()){
                st.insert(num[i]);
            }
        }
        int cnt = 1;
        for(int i = 0; i < num.size(); i++){
            if(st.find(num[i]) == st.end()) continue;
            int cur = num[i] - 1;
            int ans = 1;
            while(st.find(cur) != st.end()){
                st.erase(cur);
                ans++;
                cur--;
            }
            cur = num[i] + 1;
            while(st.find(cur) != st.end()){
                st.erase(cur);
                ans++;
                cur++;
            }
            cnt = max(cnt, ans);
        }
        return cnt;
    }
};