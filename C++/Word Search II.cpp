#include <vector>
#include <string>

class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
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
    void insert(const string &s, TrieNode *root) {
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
    void exist(vector<vector<char> > &board, int x, int y, TrieNode *root, vector<string> &res, vector<vector<int> > &vis, string str) {
        const int dx[] = {1, -1, 0, 0};
        const int dy[] = {0, 0, 1, -1};
        if (root->num > 0) {
            res.push_back(str);
            root->num = 0;
        }
        int x1, y1, c;
        for (int i = 0; i < 4; i ++) {
            x1 = x + dx[i];
            y1 = y + dy[i];
            if (x1 >= 0 && x1 < board.size() && y1 >= 0 && y1 < board[0].size() && vis[x1][y1] == 0) {
                c = board[x1][y1] - 'a';
                if (root->next[c]) {
                    vis[x1][y1] = 1;
                    string str1 = str;
                    str1 += board[x1][y1];
                    exist(board, x1, y1, root->next[c], res, vis, str1);
                    vis[x1][y1] = 0;
                }
            }
        }
    }
    vector<string> findWords(vector<vector<char> > &board, vector<string> &words) {
        // write your code here
        vector<string> res;
        if (board.empty() || words.empty()) return res;
        TrieNode *root = new TrieNode();
        for (int i = 0; i < words.size(); i ++) {
            insert(words[i], root);
        }
        int lenx = board.size(), leny = board[0].size();
        vector<vector<int> > vis(lenx, vector<int>(leny));
        for (int i = 0; i < lenx; i ++) {
            for (int j = 0; j < leny; j ++) {
                //char ch = board[i][j];
                int c = board[i][j] - 'a';
                if (root->next[c]) {
                    string str(1, board[i][j]);
                    //string str;
                    //str += board[i][j];
                    vis[i][j] = 1;
                    exist(board, i, j, root->next[c], res, vis, str);
                    vis[i][j] = 0;
                }
            }
        }
        return res;
    }
};
