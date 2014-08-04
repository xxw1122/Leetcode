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
    if(cnt+s[pos]<=target){
        st.push_back(s[pos]);
        combination(vec, st, pos, cnt+s[pos], s, target);
        st.pop_back();
    }
    else if(cnt+s[pos]>target) return;
    if(pos+1<s.size()) combination(vec, st, pos+1, cnt, s, target);
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    vector<vector<int> >vec;
    if(candidates.size()==0) return vec;
    sort(candidates.begin(),candidates.end());
    vector<int>::iterator it;
    it=unique(candidates.begin(),candidates.end());
    vector<int> st(candidates.begin(),it);
    vector<int> st1;
    combination(vec,st1,0,0,st,target);
    return vec;
}