class Solution {
public:
    void getTrans(vector<string> &tmp, unordered_map<string, vector<string>> &pre, string &end)
    {
        tmp.push_back(end);
        if(pre[end].empty())
            re.push_back(vector<string>(tmp.rbegin(),tmp.rend()));
        for(auto itr=pre[end].begin();itr!=pre[end].end();itr++)
            getTrans(tmp,pre,*itr);
        tmp.pop_back();
    }
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        re.clear();
        if(dict.empty()) return re;
        unordered_map<string, vector<string>> preMap;
        vector<unordered_set<string>> bfs(2);
        bfs[1].insert(start);
        int pre=0;
        int curr=1;
        while(1)
        {
            pre=!pre;
            curr=!curr;
            bfs[curr].clear();
            for(auto itr=bfs[pre].begin();itr!=bfs[pre].end();itr++) dict.erase(*itr);
            for(auto itr=bfs[pre].begin();itr!=bfs[pre].end();itr++)
            {
                string s=(*itr);
                for(int i=0;i<s.length();i++)
                {
                    char origchar=s[i];
                    for(char c='a';c<='z';c++)
                    {
                        if(c!=origchar)
                        {
                            s[i]=c;
                            if(dict.count(s)) {preMap[s].push_back(*itr); bfs[curr].insert(s);}
                        }
                    }
                    s[i]=origchar;
                }
            }
            if(bfs[curr].count(end)) break;
            if(bfs[curr].empty()) return re;
        }
        vector<string> tmp;
        getTrans(tmp,preMap,end);
        return re;
    }
private:
    vector<vector<string>> re;
};