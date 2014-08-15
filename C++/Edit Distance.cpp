#include <iostream>
#include <string>

int dp(int len1,int len2,string str1,string str2,int **d){
    if(d[len1][len2]!=-1) return d[len1][len2];
    if(len1==0||len2==0){
        int cnt=(len1-len2);
        if(cnt<0) cnt=-cnt;
        return d[len1][len2]=cnt;
    }
    if(str1[len1-1]==str2[len2-1]) d[len1][len2]=dp(len1-1,len2-1,str1,str2,d);
    else{
        d[len1][len2]=min(dp(len1-1,len2-1,str1,str2,d)+1,min(dp(len1-1,len2,str1,str2,d)+1,dp(len1,len2-1,str1,str2,d)+1));
    }
    return d[len1][len2];
}

int minDistance(string word1, string word2) {
    int len1=word1.size(),len2=word2.size();
    if(len1==0) return len2-len1;
    if(len2==0) return len1-len2;
    int **d=new int *[len1+1];
    for(int i=0;i<len1+1;i++){
        d[i]=new int[len2+1];
    }
    for(int i=0;i<len1+1;i++){
        for(int j=0;j<len2+1;j++){
            d[i][j]=-1;
        }
    }
    int len=dp(len1,len2,word1,word2,d);
    for(int i=0;i<len1+1;i++){
        delete []d[i];
    }
    delete []p;
    return len;
}