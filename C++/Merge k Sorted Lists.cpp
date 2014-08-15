#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct Point {
	int x;
	int y;
	bool operator <(const Point b) const {
		return x > b.x;
	}
};

static bool cmp(ListNode* cnt){
    if(cnt==NULL) return true;
    else return false;
}

ListNode *mergeKLists(vector<ListNode *> &lists) {
    if(lists.size()==0) return NULL;
    if(lists.size()==1) return lists[0];
    vector<ListNode*>::iterator it;
    it=remove_if(lists.begin(), lists.end(),cmp);
    lists.erase(it, lists.end());
    if(lists.empty()) return NULL;
    priority_queue<Point>que;
    ListNode *pre,*prenode=NULL;
    Point p;
    for(int i=0;i<lists.size();i++){
        p.x=lists[i]->val;
        p.y=i;
        que.push(p);
        lists[i]=lists[i]->next;
    }
    while(!que.empty()){
        if(prenode==NULL){
            ListNode *node=new ListNode(sizeof(ListNode));
            node->val=que.top().x;
            prenode=node;
            pre=node;
            int cnt=que.top().y;
            que.pop();
            if(lists[cnt]!=NULL){
                p.x=lists[cnt]->val;
                p.y=cnt;
                que.push(p);
                lists[cnt]=lists[cnt]->next;
            }
        }
        else{
            ListNode *node=new ListNode(sizeof(ListNode));
            node->val=que.top().x;
            prenode->next=node;
            prenode=prenode->next;
            int cnt=que.top().y;
            que.pop();
            if(lists[cnt]!=NULL){
                p.x=lists[cnt]->val;
                p.y=cnt;
                que.push(p);
                lists[cnt]=lists[cnt]->next;
            }
        }
    }
    prenode->next=NULL;
    return pre;
}