#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void combination(vector<vector<int> > &vec,vector<int> &st,int pos,int cnt,vector<int> &s,int target){
    if(cnt==target){
        vec.push_back(st);
        return;
    }
    else if(cnt>target) return;
    if(pos>=s.size()) return;
    st.push_back(s[pos]);
    combination(vec, st, pos+1, cnt+s[pos], s, target);
    st.pop_back();
    if(pos+1<s.size()) combination(vec, st, pos+1, cnt, s, target);
}

vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int> >vec;
    if(candidates.size()==0) return vec;
    sort(candidates.begin(),candidates.end());
    vector<int> st1;
    combination(vec,st1,0,0,candidates,target);
    sort(vec.begin(),vec.end());
    vector<vector<int> >::iterator it=unique(vec.begin(),vec.end());
    vector<vector<int> > vec1(vec.begin(),it);
    return vec1;
}

int main(){
    int num;
    while(cin>>num){
        vector<int> vec;
        int cnt;
        for(int i=0;i<num;i++){
            cin>>cnt;
            vec.push_back(cnt);
        }
        cin>>cnt;
        vector<vector<int> >st=combinationSum2(vec, cnt);
        for(int i=0;i<st.size();i++){
            for(int j=0;j<st[i].size();j++){
                if(j!=st[i].size()-1) cout<<st[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}