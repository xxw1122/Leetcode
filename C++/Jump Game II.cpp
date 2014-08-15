#include <iostream>

using namespace std;

int jump(int A[], int n) {
    int *dp=new int[n+1];
    for(int i=0;i<n+1;i++)
        dp[i]=0xfffffff;
    dp[0]=dp[1]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=A[i]&&j+i<=n;j++){
            dp[j+i]=min(dp[i+j],dp[i]+1);
        }
        int tag=0;
        for(int k=2;k<n;k++){
            if(dp[k]<dp[n]){
                tag=1;
                break;
            }
        }
        if(tag==0) return dp[n];
    }
    return dp[n];
}