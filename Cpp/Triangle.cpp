#include <iostream>
#include <vector>

using namespace std;

int minimumTotal(vector<vector<int> > &triangle) {
    int len=triangle.size();
    int *arry=new int[len];
    for(int i=0;i<len;i++)
        arry[i]=triangle[len-1][i];
    for(int i=len-2;i>=0;i--){
        for(int j=0;j<=i;j++){
            arry[j]=min(arry[j]+triangle[i][j],arry[j+1]+triangle[i][j]);
        }
    }
    int cnt=arry[0];
    delete []arry;
    return cnt;
}