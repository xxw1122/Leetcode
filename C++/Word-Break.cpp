class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        bool *CanBreak = new bool[s.size() + 1];
        CanBreak[0] = true;
        for (int i = 1; i <= s.size(); i ++) {
            CanBreak[i] = false;
            for (int j = 0; j < i; j ++) {
                if (CanBreak[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end()) {
                    CanBreak[i] = true;
                    break;
                }
            }
        }
        bool res = CanBreak[s.size()];
        delete []CanBreak;
        return res;
    }
};