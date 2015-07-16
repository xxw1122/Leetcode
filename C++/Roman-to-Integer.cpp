class Solution {
public:
    int romanToInt(string s) {
        map<char, int> hash;
        hash['I'] = 1, hash['V'] = 5, hash['X'] = 10, hash['L'] = 50, hash['C'] = 100,
        hash['D'] = 500, hash['M'] = 1000;
        int result = 0;
        for (int i = 0; i < s.size(); i ++) {
            if (i + 1 < s.size() && hash[s[i]] < hash[s[i + 1]]) {
                result = result - hash[s[i]];
            } else {
                result += hash[s[i]];
            }
        }
        return result;
    }
};