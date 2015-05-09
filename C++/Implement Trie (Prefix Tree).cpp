#include <string>

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

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
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

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode *cnt = root;
        for (int i = 0; i < key.length(); i ++) {
            int c = key[i] - 'a';
            if (cnt->next[c] != NULL) {
                cnt = cnt->next[c];
            } else {
                return false;
            }
        }
        if (cnt->num) return true;
        else return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *cnt = root;
        for (int i = 0; i < prefix.length(); i ++) {
            int c = prefix[i] - 'a';
            if (cnt->next[c] != NULL) {
                cnt = cnt->next[c];
            } else {
                return false;
            }
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");