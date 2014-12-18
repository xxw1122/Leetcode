class Solution {
public:
    void solve(vector<vector<string> >&vec,vector<string>&st,int vis[3][30],int n,int num){
        if(num==n){
            vec.push_back(st);
            return;
        }
        for(int i=0;i<n;i++){
            if(!vis[0][i]&&!vis[1][num+i]&&!vis[2][num-i+n]){
                vis[0][i]=vis[1][num+i]=vis[2][num-i+n]=1;
                st[num][i]='Q';
                solve(vec,st,vis,n,num+1);
                st[num][i]='.';
                vis[0][i]=vis[1][num+i]=vis[2][num-i+n]=0;
            }
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        string str="";
        vector<string> st;
        for(int i=0;i<n;i++)
            str=str+'.';
        for(int i=0;i<n;i++)
            st.push_back(str);
        int vis[3][30];
        memset(vis,0,sizeof(vis));
        vector<vector<string> >vec;
        solve(vec,st,vis,n,0);
        return vec;
    }
};