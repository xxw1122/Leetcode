/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *helper(UndirectedGraphNode* node, 
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& hash) {
        if (hash.find(node) != hash.end()) return hash[node];
        UndirectedGraphNode *cur = new UndirectedGraphNode(node->label);
        hash.insert(make_pair(node, cur));         
        for (int i = 0; i < (node->neighbors).size(); i ++) {
            (cur->neighbors).push_back(helper((node->neighbors)[i], hash));
        }
        return cur;
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return node;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hash;
        helper(node, hash);
        return hash[node];
    }
};