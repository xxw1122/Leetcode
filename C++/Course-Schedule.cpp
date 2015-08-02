class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int> > graph(numCourses);
        map<int, int> hash;
        for (int i = 0; i < prerequisites.size(); i ++) {
            int x = prerequisites[i].first, y = prerequisites[i].second;
            graph[y].push_back(x);
            if (hash.find(x) != hash.end()) {
                hash[x]++;
            } else {
                hash.insert(make_pair(x, 1));
            }
        }
        queue<int> q;
        int cur = 0;
        for (int i = 0; i < numCourses; i ++) {
            if (hash.find(i) == hash.end()) q.push(i);
        }
        while (!q.empty()) {
            int cnt = q.front();
            cur ++;
            q.pop();
            for (int i = 0; i < graph[cnt].size(); i ++) {
                int temp = graph[cnt][i];
                if (hash.find(temp) != hash.end()) {
                    hash[temp] --;
                    if (hash[temp] == 0) {
                        q.push(temp);
                    }
                }
            }
        }
        return cur == numCourses;
    }
};

class Solution {
public:
    bool dfs_circle(vector<vector<int> >&graph, vector<int> &vis, int pos) {
        vis[pos] = 1;
        for (int i = 0; i < graph[pos].size(); i ++) {
            int cnt = graph[pos][i];
            if (cnt != pos) {
                if (vis[cnt] == 1) return true;
                else if (vis[cnt] == 0) {
                    if (dfs_circle(graph, vis, cnt)) return true;
                }
            }
        }
        vis[pos] = 2;
        return false;
    }
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<vector<int> > graph(numCourses);
        vector<int> vis(numCourses);
        for (int i = 0; i < prerequisites.size(); i ++) {
            graph[prerequisites[i].first].push_back(prerequisites[i].second);
            //graph[prerequisites[i].first][prerequisites[i].second] = 1;
        }
        for (int i = 0; i < numCourses; i ++) {
            if (vis[i] == 0) {
                if (dfs_circle(graph, vis, i)) return false;
            }
        }
        return true;
    }
};

