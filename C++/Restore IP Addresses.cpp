#include <string>
#include <vector>

int str2int(const string&str,int left,int right){
    int sum=0;
    for(int i=left;i<=right;i++){
        sum=sum*10+str[i]-'0';
    }
    return sum;
}

void gernerate(vector<string>&vec,const string &str,string st,int pos,int now,int num){
    if(pos>=str.size()||now>=str.size()) return;
    if(num==3&&pos<str.size()){
        if(pos<str.size()-1&&str[pos]=='0') return;
        int cnt=str2int(str,pos,str.size()-1);
        if(cnt>=0&&cnt<=255){
            string s=st;
            for(int i=pos;i<str.size();i++){
                s=s+str[i];
            }
            vec.push_back(s);
        }
        return;
    }
    int cnt=str2int(str,pos,now);
    if(cnt>=0&&cnt<=255){
        string s=st;
        for(int i=pos;i<=now;i++){
            s=s+str[i];
        }
        s=s+'.';
        gernerate(vec,str,s,now+1,now+1,num+1);
    }
    if(str[pos]!='0') gernerate(vec,str,st,pos,now+1,num);
    return;
}

vector<string> restoreIpAddresses(string s) {
    vector<string> vec;
    string str;
    gernerate(vec,s,str,0,0,0);
    return vec;
}