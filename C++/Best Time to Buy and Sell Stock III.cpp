#include <vector>

int maxProfit(vector<int> &prices) {
    int len=prices.size();
    if(len<=1) return 0;
    int *dp1=new int[len];
    dp1[0]=0;
    int maxv=prices[0],minv=prices[0],maxp=0,maxnum=0;
    for(int i=0;i<len;i++){
        if(prices[i]>maxv){
            maxp=max(maxp,prices[i]-minv);
        }
        dp1[i]=maxp;
        if(prices[i]<minv){
            minv=prices[i];
            maxv=minv;
        }
        maxnum=max(maxnum,maxp);
    }
    int *dp2=new int[len];
    dp2[len-1]=0;
    maxv=prices[len-1],minv=prices[len-1],maxp=0;
    for(int i=len-1;i>=0;i--){
        if(prices[i]<minv){
            maxp=max(maxp,maxv-prices[i]);
        }
        dp2[i]=maxp;
        if(prices[i]>maxv){
            maxv=prices[i];
            minv=maxv;
        }
    }
    for(int i=0;i<len;i++){
        int cnt=dp1[i]+dp2[i];
        maxnum=max(maxnum,cnt);
    }
    return maxnum;
}