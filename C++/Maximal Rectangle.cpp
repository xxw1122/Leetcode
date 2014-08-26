#include <vector>

int maximalRectangle(vector<vector<char> > &matrix) {
    int len1=matrix.size();
    if(len1==0) return 0;
    int len2=matrix[0].size();
    const int maxn=500;
    int up[maxn][maxn],left[maxn][maxn],right[maxn][maxn];
    int ans=0;
    for(int i=0;i<len1;i++){
        int lo=-1,ro=len2;
        for(int j=0;j<len2;j++){
            if(matrix[i][j]=='0'){
                up[i][j]=left[i][j]=0;
                lo=j;
            }
            else{
                up[i][j]=i==0?1:up[i-1][j]+1;
                left[i][j]=i==0?lo+1:max(left[i-1][j],lo+1);
            }
        }
        for(int j=len2-1;j>=0;j--){
            if(matrix[i][j]=='0'){
                right[i][j]=len2;
                ro=j;
            }
            else{
                right[i][j]=i==0?ro-1:min(right[i-1][j],ro-1);
                ans=max(ans,up[i][j]*(right[i][j]-left[i][j]+1));
            }
        }
    }
    return ans;
}