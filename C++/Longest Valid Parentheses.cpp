#include <stack>
#include <string>
#include <iostream>

using namespace std;

int longestValidParentheses(string s) {
    int len=s.size(),maxlen=0,cnt=0;
    int vis[len];
    memset(vis,0,sizeof(int)*len);
    stack<char>st;
    int pos=0;
    for(int i=0;i<len;i++){
        if(s[i]==')'&&st.empty()){
            cnt=0;
            memset(vis,0,sizeof(int)*len);
        }
        else if(s[i]==')'&&st.top()=='('){
            st.pop();
            pos--;
            vis[pos]=vis[pos]+2+vis[pos+1];
            vis[pos+1]=0;
            maxlen=max(maxlen,vis[pos]);
        }
        else if(s[i]=='('){
            pos++;
            st.push(s[i]);
        }
    }
    return maxlen;
}

int main(){
    string str;
    while(cin>>str){
        int cnt=longestValidParentheses(str);
        cout<<cnt<<endl;
    }
}