class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> hash;
        set<char> st;
        for (int i = 0; i < s.size(); i ++) {
            if (hash.find(s[i]) == hash.end()) {
                if (st.find(t[i]) != st.end()) return false;
                else {
                    hash[s[i]] = t[i];
                    st.insert(t[i]);
                }
            } else {
                if (hash[s[i]] != t[i]) return false;
            }
        }
        return true;
    }
};