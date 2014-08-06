#include <iostream>
#include <vector>

using namespace std;

void solve(vector<vector<char> >&board,int x,int y,vector<vector<char> >&st,int vis1[10][10],int vis2[10][10],int vis3[10][10]){
    if(y>=9){
        y=0;
        x++;
    }
    if(x>8){
        st.assign(board.begin(), board.end());
        return;
    }
    while(board[x][y]!='.'){
        if(y<8) y++;
        else{
            x++;
            y=0;
        }
        if(x>8){
            st.assign(board.begin(), board.end());
            return;
        }
    }
    for(int i=1;i<=9;i++){
        int x1=x/3;
        int y1=y/3;
        int cur=x1*3+y1;
        if(!vis1[x][i]&&!vis2[y][i]&&!vis3[cur][i]){
            vis1[x][i]=vis2[y][i]=vis3[cur][i]=1;
            board[x][y]='0'+i;
            solve(board,x,y+1,st,vis1,vis2,vis3);
            board[x][y]='.';
            vis1[x][i]=vis2[y][i]=vis3[cur][i]=0;
        }
    }
}


void solveSudoku(vector<vector<char> > &board) {
    int vis1[10][10],vis2[10][10],vis3[10][10];
    memset(vis1,0,sizeof(vis1));
    memset(vis2,0,sizeof(vis2));
    memset(vis3,0,sizeof(vis3));
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]!='.'){
                int cnt=board[i][j]-'0';
                vis1[i][cnt]=1;
                vis2[j][cnt]=1;
                int x1=i/3;
                int y1=j/3;
                int cur=x1*3+y1;
                vis3[cur][cnt]=1;
            }
        }
    }
    vector<vector<char> >st;
    solve(board,0,0,st,vis1,vis2,vis3);
    board.assign(st.begin(), st.end());
}