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