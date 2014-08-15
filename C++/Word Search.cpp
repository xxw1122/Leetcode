#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool search(vector<vector<char> >&board,string &word,int pos,int x,int y,int len1,int len2,int **vis){
    if(pos>=word.size()) return true;
    if(x+1<len1&&board[x+1][y]==word[pos]&&vis[x+1][y]==0){
        vis[x+1][y]=1;
        if(search(board,word,pos+1,x+1,y,len1,len2,vis)) return true;
        vis[x+1][y]=0;
    }
    if(x-1>=0&&board[x-1][y]==word[pos]&&vis[x-1][y]==0){
        vis[x-1][y]=1;
        if(search(board,word,pos+1,x-1,y,len1,len2,vis)) return true;
        vis[x-1][y]=0;
    }
    if(y+1<len2&&board[x][y+1]==word[pos]&&vis[x][y+1]==0){
        vis[x][y+1]=1;
        if(search(board,word,pos+1,x,y+1,len1,len2,vis)) return true;
        vis[x][y+1]=0;
    }
    if(y-1>=0&&board[x][y-1]==word[pos]&&vis[x][y-1]==0){
        vis[x][y-1]=1;
        if(search(board,word,pos+1,x,y-1,len1,len2,vis)) return true;
        vis[x][y-1]=0;
    }
    return false;
}

bool exist(vector<vector<char> > &board, string word) {
    int len1=board.size();
    if(len1==0) return false;
    if(word=="") return false;
    int len2=board[0].size();
    int **vis=new int*[len1];
    for(int i=0;i<len1;i++){
        vis[i]=new int[len2];
    }
    for(int i=0;i<len1;i++){
        for(int j=0;j<len2;j++){
            vis[i][j]=0;
        }
    }
    for(int i=0;i<len1;i++){
        for(int j=0;j<len2;j++){
            if(board[i][j]==word[0]){
                vis[i][j]=1;
                if(search(board,word,1,i,j,len1,len2,vis)){
                    for(int k=0;k<len1;k++){
                        delete []vis[k];
                    }
                    delete []vis;
                    return true;
                }
                vis[i][j]=0;
            }
        }
    }
    for(int k=0;k<len1;k++){
        delete []vis[k];
    }
    delete []vis;
    return false;
}