#include <string>
#include <map>
#include <set>

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> st;
        set<char> h;
        for (int i = 0; i < s.size(); i ++) {
            if (st.find(s[i]) == st.end()) {
                if (h.find(t[i]) != h.end()) return false;
                else {
                    h.insert(t[i]);
                    st[s[i]] = t[i];
                }
            } else {
                if (t[i] != st[s[i]]) return false;
            }
        }
        return true;
    }
};