class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        unordered_map<string, int> hash;
        if (wordDict.find(beginWord) != wordDict.end()) wordDict.erase(beginWord);
        if (wordDict.find(endWord) == wordDict.end()) wordDict.insert(endWord);
        queue<string> q;
        q.push(beginWord);
        hash[beginWord] = 1;
        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            if (cur == endWord) return hash[cur];
            int dis = hash[cur];
            for (int i = 0; i < cur.size(); i ++) {
                for (int j = 0; j < 26; j ++) {
                    char ch = 'a' + j;
                    string temp = cur;
                    temp[i] = ch;
                    if (temp != cur && wordDict.find(temp) != wordDict.end() && hash.find(temp) == hash.end()) {
                        hash[temp] = dis + 1;
                        wordDict.erase(temp);
                        q.push(temp);
                    }
                }
            }
        }
        return 0;
    }
};