#include <string>
#include <stack>

string simplifyPath(string path) {
    stack<string> st;
    int pos=0,lenth=path.size();
    while(pos<lenth){
        string str="";
        while(pos<lenth&&path[pos]=='/'){
            pos++;
        }
        while(pos<lenth&&path[pos]!='/'){
            str=str+path[pos];
            pos++;
        }
        if(str==".") continue;
        else if(str==".."){
            if(!st.empty()) st.pop();
        }
        else if(str!="") st.push(str);
    }
    string str="";
    if(st.empty()) return str="/";
    stack<string> st1;
    while(!st.empty()){
        st1.push(st.top());
        st.pop();
    }
    while(!st1.empty()){
        str=str+"/"+st1.top();
        st1.pop();
    }
    return str;
}