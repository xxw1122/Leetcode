class Solution {
private:
    int caldis(string x,string y)
    {
        int dis = 0;
        for(int i=0; i<x.length(); i++)
            if(x[i]!=y[i])
                dis++;
        return dis;
    }
    void dfs(unordered_map<string,vector<string> > &mp,string cur,vector<string> &now,vector<vector<string> > &ans)
    {
        now.push_back(cur);
        if(mp[cur].size()==0)
        {
            vector<string> tmp(now);
            reverse(tmp.begin(),tmp.end());
            ans.push_back(tmp);
            now.pop_back();
            return;
        }
        for(int i=0; i<mp[cur].size(); i++)
        {
            dfs(mp,mp[cur][i],now,ans);
        }
        now.pop_back();
    }
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        vector<string> now;
        vector<vector<string> > ans;
        if(start==end)
        {
            now.push_back(end);
            ans.push_back(now);
            return ans;
        }
        unordered_set<string> qu[2];
        unordered_map<string,vector<string> > mp;
        for(auto it=dict.begin(); it!=dict.end(); it++)
        {
            mp[*it] = vector<string>();
        }
        qu[0].insert(start);
        int i=0;
        bool isdone = false;
        while(!qu[i].empty())
        {
            i = 1-i;
            qu[i].clear();
            for(auto it=qu[1-i].begin(); it!=qu[1-i].end(); it++)
            {
                if(caldis(*it,end)==1)
                {
                    isdone = true;
                    mp[end].push_back(*it);
                }
                dict.erase(*it);
            }
            if(isdone) break;
            for(auto it=qu[1-i].begin(); it!=qu[1-i].end(); it++)
            {
                string cur = *it;
                for(int j=0; j<cur.size(); j++)
                {
                    for(char ch='a'; ch<='z'; ch++)
                    {
                        string tmp = cur;
                        tmp[j] = ch;
                        if(dict.find(tmp)!=dict.end())
                        {
                            mp[tmp].push_back(cur);
                            qu[i].insert(tmp);
                        }
                    }
                }
            }
        }
        ans.clear();
        now.clear();
        if(!isdone) return ans;
        dfs(mp,end,now,ans);
        return ans;
    }
};