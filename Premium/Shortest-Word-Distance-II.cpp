class WordDistance {
public:
    unordered_map<string, vector<int> > hash;
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); i ++) {
            if (hash.find(words[i]) != hash.end()) {
                hash[words[i]].push_back(i);
            } else {
                vector<int> cur;
                cur.push_back(i);
                hash.insert(make_pair(words[i], cur));
            }
        }
    }

    int shortest(string word1, string word2) {
        vector<int> cur1 = hash[word1];
        vector<int> cur2 = hash[word2];
        int res = INT_MAX;
        for (int i = 0; i < cur1.size(); i ++) {
            for (int j = 0; j < cur2.size(); j ++) {
                res = min(res, abs(cur1[i] - cur2[j]));
            }
        }
        return res;
    }
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");