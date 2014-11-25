#include <iostream>
#include <vector>

using namespace std;


vector<int> spiralOrder(vector<vector<int> > &matrix) {
    int len1=matrix.size();
    vector<int> vec;
    if(len1==0) return vec;
    int len2=matrix[0].size();
    int x=0,y=0;
    vec.push_back(matrix[x][y]);
    int cnt=1;
    int **arry=new int *[len1];
    for(int i=0;i<len1;i++)
        arry[i]=new int[len2];
    for(int i=0;i<len1;i++){
        for(int j=0;j<len2;j++)
            arry[i][j]=0;
    }
    arry[0][0]=1;
    while(cnt<len1*len2){
        while(y+1<len2&&!arry[x][y+1]){
            cnt++;
            arry[x][++y]=1;
            vec.push_back(matrix[x][y]);
        }
        while(x+1<len1&&!arry[x+1][y]){
            cnt++;
            arry[++x][y]=1;
            vec.push_back(matrix[x][y]);
        }
        while(y-1>=0&&!arry[x][y-1]){
            cnt++;
            arry[x][--y]=1;
            vec.push_back(matrix[x][y]);
        }
        while(x-1>=0&&!arry[x-1][y]){
            cnt++;
            arry[--x][y]=1;
            vec.push_back(matrix[x][y]);
        }
    }
    for(int i=0;i<len1;i++)
        delete []arry[i];
    delete []arry;
    return vec;
}