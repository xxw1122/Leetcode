#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string> &strs) {
    int len=strs.size();
    string str="";
    if(len==0) return str;
    sort(strs.begin(),strs.end());
    string str1=strs[0],str2=strs[len-1];
    for(int i=0;i<str1.size()&&i<str2.size();i++){
        if(str1[i]==str2[i]) str=str+str1[i];
        else break;
    }
    return str;
}