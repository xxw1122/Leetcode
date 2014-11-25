#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > vec;
        if(n==0) return vec;
        int **arry=new int *[n];
        for(int i=0;i<n;i++){
            arry[i]=new int[n];
        }
        int tot=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) arry[i][j]=0;
        }
        int x=0,y=0;
        arry[x][y]=++tot;
        while(tot<n*n){
            while(y+1<n&&!arry[x][y+1]) arry[x][++y]=++tot;
            while(x+1<n&&!arry[x+1][y]) arry[++x][y]=++tot;
            while(y-1>=0&&!arry[x][y-1]) arry[x][--y]=++tot;
            while(x-1>=0&&!arry[x-1][y]) arry[--x][y]=++tot;
        }
        for(int i=0;i<n;i++){
            vector<int> vc;
            for(int j=0;j<n;j++){
                vc.push_back(arry[i][j]);
            }
            vec.push_back(vc);
        }
        for(int i=0;i<n;i++)
            delete []arry[i];
        delete []arry;
        return vec;
    }
};