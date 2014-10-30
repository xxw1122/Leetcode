#include <iostream>
#include <algorithm>
#include <vector>

static bool cmp(int x,int y){
    return x<y;
}

int longestConsecutive(vector<int> &num) {
    int len=num.size();
    if(len==0||len==1) return len;
    sort(num.begin(),num.end(),cmp);
    int len1=1,cnt=num[0];
    int maxlen=len1;
    for(int i=1;i<len;i++){
        if(num[i]==cnt+1){
            cnt++;
            len1++;
            maxlen=max(maxlen,len1);
        }
        else if(num[i]>cnt+1){
            cnt=num[i];
            len1=1;
        }
    }
    return maxlen;
}