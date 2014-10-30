#include <iostream>
#include <string>
#include <vector>

using namespace std;

int palindrome(int left,int right,const string &str){
    if(left==right) return 1;
    for(int i=left;i<=(left+right)/2;i++)
        if(str[i]!=str[right+left-i]) return 0;
    return 1;
}

void gernerate(vector<vector<string> >&vec,vector<string>&st,int start,int end,string &s,int **dp){
    if(start==end){
        vec.push_back(st);
        return;
    }
    for(int i=start;i<end;i++){
        if(dp[start][i]){
            string str="";
            for(int j=start;j<=i;j++)
                str=str+s[j];
            st.push_back(str);
            gernerate(vec, st, i+1, end,s,dp);
            st.pop_back();
        }
    }
}

vector<vector<string> > partition(string s) {
    vector<vector<string> >vec;
    int len=s.size();
    int **dp=new int*[len];
    for(int i=0;i<len;i++)
        dp[i]=new int[len];
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            if(i>j) dp[i][j]=0;
            else dp[i][j]=palindrome(i, j, s);
        }
    }
    vector<string>st;
    gernerate(vec, st, 0, len, s,dp);
    return vec;
}