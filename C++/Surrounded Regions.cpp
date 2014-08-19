#include <vector>

void judge(vector<vector<char> >&board,int **vis,int x,int y,int& tag){
    int len=board.size();
    if(x<0||y<0||x>=len||y>=board[x].size()||vis[x][y]==1||board[x][y]=='X') return;
    vis[x][y]=1;
    if(x==0||y==0||x==len-1||y==board[x].size()-1) tag=1;
    judge(board,vis,x+1,y,tag);
    judge(board,vis,x,y+1,tag);
    judge(board,vis,x-1,y,tag);
    judge(board,vis,x,y-1,tag);
    return;
}

void flip(vector<vector<char> >&board,int x,int y){
    int len=board.size();
    if(x<0||y<0||x>=len||y>=board[x].size()||board[x][y]=='X') return;
    board[x][y]='X';
    flip(board,x+1,y);
    flip(board,x,y+1);
    flip(board,x-1,y);
    flip(board,x,y-1);
}

void solve(vector<vector<char> > &board) {
    int len=board.size();
    int **vis=new int*[len];
    for(int i=0;i<len;i++){
        int cnt=board[i].size();
        vis[i]=new int[cnt];
    }
    for(int i=0;i<len;i++){
        for(int j=0;j<board[i].size();j++){
            vis[i][j]=0;
        }
    }
    for(int i=0;i<len;i++){
        for(int j=0;j<board[i].size();j++){
            if(vis[i][j]==0&&board[i][j]=='O'){
                int tag=0;
                judge(board, vis, i, j, tag);
                if(tag==0){
                    flip(board,i,j);
                }
            }
        }
    }
}