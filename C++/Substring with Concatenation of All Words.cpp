#include <string>
#include <map>
#include <set>

vector<int> findSubstring(string S, vector<string> &L) {
    vector<int> vec;
    int num=L.size();
    if(num==0) return vec;
    int len1=L[0].size(),len2=S.size();
    map<string,int> st,st1;
    int lenth=len1*num;
    for(int i=0;i<num;i++){
        st[L[i]]++;
    }
    for(int i=0;i+lenth-1<len2;i++){
        st1.clear();
        int j;
        for(j=0;j<num;j++){
            string str=S.substr(i+j*len1,len1);
            if(st.find(str)!=st.end()&&st1[str]<st[str]){
                    st1[str]++;
            }
            else break;
        }
        if(j==num){
            vec.push_back(i);
        }
    }
    return vec;
}