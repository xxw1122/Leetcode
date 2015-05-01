#include <unordered_set>
#include <queue>
#include <pair>
#include <map>
#include <string>

class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // write your code here
        if (start == end) return 1;
        queue<pair<string, int> >que;
        unordered_set<string> st;
        que.push(make_pair(start, 1));
        st.insert(start);
        if (dict.find(start) != dict.end()) dict.erase(start);
        while (!que.empty()) {
            string str = que.front().first, s;
            int len = que.front().second;
            if (str == end) return len;
            len ++;
            que.pop();
            for (int i = 0; i < str.size(); i ++) {
                for (int j = 0; j < 26; j ++) {
                    s = str;
                    s[i] = j + 'a';
                    if (dict.find(s) != dict.end() && st.find(s) == st.end()) {
                        st.insert(s);
                        dict.erase(s);
                        que.push(make_pair(s, len));
                    }
                }
            }
        }
        return 0;
    }
};
