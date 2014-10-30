#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string int2string(int num){
    stringstream ss;
    ss<<num;
    string str=ss.str();
    return str;
}

string convert(string str){
    int cnt=1;
    char ch=str[0];
    string st="";
    if(str.size()==1){
        st=st+int2string(cnt);
        st=st+ch;
    }
    for(int i=1;i<str.size();i++){
        if(str[i]==ch){
            cnt++;
            if(i==str.size()-1){
                st=st+int2string(cnt);
                st=st+ch;
            }
        }
        else{
            st=st+int2string(cnt);
            st=st+ch;
            ch=str[i];
            cnt=1;
            if(i==str.size()-1){
                st=st+int2string(cnt);
                st=st+ch;
            }
        }
    }
    return st;
}

string countAndSay(int n) {
    string str="1";
    if(n==1) return str;
    int num=n-1;
    while(num--){
        str=convert(str);
    }
    return str;
}