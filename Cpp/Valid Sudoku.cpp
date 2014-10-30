#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int len=board.size();
        int arry[15];
        for(int i=0;i<len;i++){
            memset(arry,0,sizeof(arry));
            for(int j=0;j<len;j++){
                if(board[i][j]!='.'){
                    int cnt=board[i][j]-'0';
                    if(arry[cnt]==1) return false;
                    arry[cnt]=1;
                }
            }
        }
        for(int j=0;j<len;j++){
            memset(arry,0,sizeof(arry));
            for(int i=0;i<len;i++){
                if(board[i][j]!='.'){
                    int cnt=board[i][j]-'0';
                    if(arry[cnt]==1) return false;
                    arry[cnt]=1;
                }
            }
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                memset(arry,0,sizeof(arry));
                for(int x=i*3;x<i*3+3;x++){
                    for(int y=j*3;y<j*3+3;y++){
                        if(board[x][y]!='.'){
                            int cnt=board[x][y]-'0';
                            if(arry[cnt]==1) return false;
                            arry[cnt]=1;
                        }
                    }
                }
            }
        }
        return true;
    }
};