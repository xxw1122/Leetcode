class TrieNode {
public:
    // Initialize your data structure here.
    int num;
    TrieNode* next[26];
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
    void insert(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.size(); i ++) {
            int temp = word[i] - 'a';
            if (cur->next[temp] == NULL) {
                TrieNode* node = new TrieNode();
                cur->next[temp] = node;
            }
            cur = cur->next[temp];
        }
        cur->num = 1;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.size(); i ++) {
            int temp = word[i] - 'a';
            if (cur->next[temp] == NULL) {
                return false;
            }
            cur = cur->next[temp];
        }
        if (cur->num > 0) return true;
        else return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (int i = 0; i < prefix.size(); i ++) {
            int temp = prefix[i] - 'a';
            if (cur->next[temp] == NULL) {
                return false;
            }
            cur = cur->next[temp];
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