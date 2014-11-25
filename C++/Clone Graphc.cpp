#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if(node==NULL) return NULL;
    queue<UndirectedGraphNode*>st1;
    map<int,UndirectedGraphNode*>st2;
    UndirectedGraphNode *root=new UndirectedGraphNode(sizeof(UndirectedGraphNode));
    root->label=node->label;
    st2.insert(make_pair(node->label, root));
    st1.push(node);
    while(!st1.empty()){
        int cur=st1.front()->label;
        for(int i=0;i<st1.front()->neighbors.size();i++){
            int cnt=(st1.front()->neighbors)[i]->label;
            if(st2.count(cnt)==0){
                st1.push((st1.front()->neighbors)[i]);
                UndirectedGraphNode* root1=new UndirectedGraphNode(sizeof(UndirectedGraphNode));
                root1->label=cnt;
                st2[cur]->neighbors.push_back(root1);
                st2.insert(make_pair(cnt,root1));
            }
            else{
                st2[cur]->neighbors.push_back(st2[cnt]);
            }
        }
        st1.pop();
    }
    return root;
}