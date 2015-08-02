class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
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
        vector<int> res;
        for (int i = 0; i < numCourses; i ++) {
            if (hash.find(i) == hash.end()) q.push(i);
        }
        while (!q.empty()) {
            int cnt = q.front();
            res.push_back(cnt);
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
        if (res.size() == numCourses) return res;
        else {
            res.clear();
            return res;
        }
    }
};

class Solution {
public:
    bool dfs(vector<vector<int> > &graph, vector<int> &vis, vector<int> &res, int pos) {
        vis[pos] = 1;
        for (int i = 0; i < graph[pos].size(); i ++) {
            int cnt = graph[pos][i];
            if (vis[cnt] == 1) return true;
            else if (vis[cnt] == 0) {
                if (dfs(graph, vis, res, cnt)) return true;
                res.push_back(cnt);
            }
        }
        vis[pos] = 2;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<vector<int> > graph(numCourses);
        vector<int> vis(numCourses), res;
        for (int i = 0; i < prerequisites.size(); i ++) {
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
            //graph[prerequisites[i].first][prerequisites[i].second] = 1;
        }
        for (int i = 0; i < numCourses; i ++) {
            if (vis[i] == 0) {
                if (dfs(graph, vis, res, i)) {
                    vector<int> circle;
                    return circle;
                }
                res.push_back(i);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};