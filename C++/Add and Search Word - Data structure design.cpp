#include <string>

class WordDictionary {
public:
    class TrieNode {
    public:
        // Initialize your data structure here.
        TrieNode* next[26];
        int num;
        TrieNode() {
            for (int i = 0; i < 26; i ++) {
                this->next[i] = NULL;
            }
            num = 0;
        }
    };
    TrieNode *root = new TrieNode();
    // Adds a word into the data structure.
    void addWord(string s) {
        TrieNode *cnt = root;
        for (int i = 0; i < s.length(); i ++) {
            int c = s[i] - 'a';
            if (cnt->next[c] != NULL) {
                cnt = cnt->next[c];
            } else {
                TrieNode *res = new TrieNode();
                cnt->next[c] = res;
                cnt = cnt->next[c];
            }
        }
        cnt->num = 1;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool find(string &word, int pos, TrieNode *root) {
        if (pos == word.length() && root->num > 0) return true;
        else if (pos == word.length()) return false;
        if (word[pos] == '.') {
            for (int i = 0; i < 26; i ++) {
                if (root->next[i] != NULL && find(word, pos + 1, root->next[i])) return true;
            }
        } else {
            int c = word[pos] - 'a';
            if (root->next[c] != NULL) return find(word, pos + 1, root->next[c]);
        }
        return false;
    }
    bool search(string word) {
        return find(word, 0, root);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");