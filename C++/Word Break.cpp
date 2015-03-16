class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    bool wordBreak(string s, unordered_set<string> &dict) {
        // write your code here
        int len = s.size();
        vector<int> vec(len + 1);
        vec[0] = 1;
        for (int i = 1; i <= len; i ++) {
            for (int j = i; j >= 1; j --) {
                string str = s.substr(j-1, i - j + 1);
                if (vec[j-1] == 1 && dict.find(str) != dict.end()) {
                    vec[i] = 1;
                    break;
                }
            }
        }
        return vec[len];
    }
};
