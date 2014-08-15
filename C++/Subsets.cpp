#include<iostream>
#include<vector>
#include<algorithm>

static bool cmp(int x,int y){
    return x<y;
}


void generate(vector<vector<int> >&vec,vector<int> &st,vector<int>& S,int pos,int len)
    {
        if(pos==len)
            {
                vec.push_back(st);
                return;
            }
        st.push_back(S[pos]);
        generate(vec, st, S, pos+1, len);
        st.pop_back();
        generate(vec, st, S, pos+1, len);
    }

vector<vector<int> > subsets(vector<int> &S)
    {
        vector<vector<int> > vec;
        vector<int> st;
        int len=S.size();
        sort(S.begin(),S.end(),cmp);
        generate(vec, st,S,0,len);
        return vec;
    }