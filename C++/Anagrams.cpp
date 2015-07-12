class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        map<string, vector<string> >hash;
        for (int i = 0; i < strs.size(); i ++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (hash.find(s) != hash.end()) {
                hash[s].push_back(strs[i]);
            } else {
                vector<string> temp;
                temp.push_back(strs[i]);
                hash.insert(make_pair(s, temp));
            }
        }
        vector<string> res;
        for (auto it = hash.begin(); it != hash.end(); it ++) {
            if ((*it).second.size() >= 2) {
                for (int i = 0; i < (*it).second.size(); i ++) {
                    res.push_back(((*it).second)[i]);
                }
            }
        }
        return res;
    }
};