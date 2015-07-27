class Solution {
public:
    bool isMatch(string s, string p) {
        int lens = s.size(), lenp = p.size();
        vector<vector<bool> > match(lens + 1, vector<bool>(lenp + 1, false));
        match[0][0] = true;
        for (int i = 0; i < lenp; i ++) {
            if (p[i] == '*' && i > 0) match[0][i + 1] = match[0][i - 1];
        }
        for (int i = 0; i < lens; i ++) {
            for (int j = 0; j < lenp; j ++) {
                if (p[j] != '*' && (s[i] == p[j] || p[j] == '.'))
                    match[i + 1][j + 1] = match[i][j];
                else if (p[j] == '*' && j > 0) {
                    if (match[i + 1][j - 1]) 
                        match[i + 1][j + 1] = true;
                    else if (match[i + 1][j]) 
                        match[i + 1][j + 1] = true;
                    else if (match[i][j + 1] && (p[j - 1] == '.' || p[j - 1] == s[i]))
                        match[i + 1][j + 1] = true;
                }
            }
        }
        return match[lens][lenp];        
    }
};