#include <iostream>
#include <string>

using namespace std;

string addBinary(string a, string b) {
    string str="";
    int d=0;
    int len1=a.size(),len2=b.size();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int i;
    for(i=0;i<len1&&i<len2;i++){
        int cnt=d+a[i]-'0'+b[i]-'0';
        if(cnt>1){
            d=1;
            cnt=cnt%2;
            char ch='0'+cnt;
            str=str+ch;
        }
        else{
            d=0;
            char ch='0'+cnt;
            str=str+ch;
        }
    }
    if(i<len1&&i==len2){
        while(i<len1){
            int cnt=d+a[i]-'0';
            if(cnt>1){
                d=1;
                cnt=0;
                str=str+'0';
            }
            else{
                d=0;
                char ch='0'+cnt;
                str=str+ch;
            }
            i++;
        }
        if(d==1) str=str+'1';
    }
    else if(i<len2&&i==len1){
        while(i<len2){
            int cnt=d+b[i]-'0';
            if(cnt>1){
                d=1;
                cnt=0;
                str=str+'0';
            }
            else{
                d=0;
                char ch='0'+cnt;
                str=str+ch;
            }
            i++;
        }
        if(d==1) str=str+'1';
    }
    else if(i==len1&&i==len2&&d==1){
        str=str+'1';
        d=0;
    }
    reverse(str.begin(),str.end());
    return str;
}