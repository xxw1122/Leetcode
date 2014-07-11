#include<iostream>


void search(int cur,int &tot,int lenth,int vis[3][30],int *pos)
    {
        if(cur==lenth) tot++;
        else
            {
                for(int i=0;i<lenth;i++)
                    {
                        if(!vis[0][i]&&!vis[1][cur+i]&&!vis[2][cur-i+n])
                            {
                                pos[cur]=i;
                                vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]=1;
                                search(cur+1,tot,lenth,vis,pos);
                                vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]=0;
                            }
                    }
            }
    }

int totalNQueens(int n)
    {
        int vis[3][30],pos[30];
        memset(vis,0,sizeof(vis));
        int total=0;
        search(0,total,n,vis,pos);
        return total;
    }