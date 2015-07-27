class Solution {
public:
    void search(int cur,int &tot,int lenth,int vis[3][30]){
        if(cur==lenth) tot++;
        else{
            for(int i=0;i<lenth;i++){
                if(!vis[0][i]&&!vis[1][cur+i]&&!vis[2][cur-i+lenth]){
                    vis[0][i]=vis[1][cur+i]=vis[2][cur-i+lenth]=1;
                    search(cur+1,tot,lenth,vis);
                    vis[0][i]=vis[1][cur+i]=vis[2][cur-i+lenth]=0;
                }
            }
        }
    }

    int totalNQueens(int n){
        int vis[3][30];
        memset(vis,0,sizeof(vis));
        int total=0;
        search(0,total,n,vis);
        return total;
    }
};