class Node {
public:
    int dist;
    string str;
    vector<Node*> prev;
    Node (int dist, string str) {
        this->dist = dist;
        this->str = str;
    }
};

class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return a list of lists of string
      */
    void getPath(vector<vector<string> >& Path, vector<string> &cur, unordered_map<string, Node*>& hash, Node* end) {
        if (end == NULL) {
            reverse(cur.begin(), cur.end());
            Path.push_back(cur);
            reverse(cur.begin(), cur.end());
            return;
        }
        cur.push_back(end->str);
        if (!(end->prev).empty()) {
            for (int i = 0; i < (end->prev).size(); i ++) {
                getPath(Path, cur, hash, (end->prev)[i]);
            }
        } else {
            getPath(Path, cur, hash, NULL);
        }
        cur.pop_back();
    }
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        // write your code here
        dict.insert(end);
        unordered_map<string, Node*> hash;
        vector<vector<string> > res;
        queue<string> q;
        Node *startnode = new Node(1, start);
        q.push(start);
        hash[start] = startnode;
        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            if (cur == end) {
                vector<string> cur;
                getPath(res, cur, hash, hash[end]);
                return res;
            }
            for (int i = 0; i < cur.size(); i ++) {
                for (int j = 0; j < 26; j ++) {
                    string temp = cur;
                    temp[i] = 'a' + j;
                    if (dict.find(temp) != dict.end()) {
                        Node *node = hash[cur];
                        if (hash.find(temp) == hash.end()) {
                            Node *new_node = new Node(node->dist + 1, temp);
                            (new_node->prev).push_back(node);
                            hash[temp] = new_node;
                            q.push(temp);
                        } else {
                            Node *pnode = hash[temp];
                            if (pnode->dist == node->dist + 1) {
                                (pnode->prev).push_back(node);
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};
