class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (abs((int)s.size() - (int)t.size()) > 1) return false;

        if (t.size() == s.size()) {
            for (int i = 0; i < t.size(); i++) {
                if (s[i] != t[i]) {
                    return (s.substr(i + 1) == t.substr(i + 1));
                }
            }
            return false;
        } else {
            string& shortest = (s.size() < t.size() ? s : t);
            string& longest = (s.size() > t.size() ? s : t);

            for (int i = 0; i < shortest.size(); i++) {
                if (shortest[i] != longest[i]) {
                    return (shortest.substr(i) == longest.substr(i + 1));
                }
            }
            return true;
        }
    }
};

