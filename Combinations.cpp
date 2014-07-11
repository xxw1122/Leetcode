#include<iostream>
#include<vector>

void generate(vector<vector<int> >&vec,vector<int>&st,int pos,int num,int cnt,int len)
    {
        if(cnt==len)
            {
                vec.push_back(st);
                return;
            }
        if(cnt+num-pos+1<len) return;
        if(cnt+num-pos+1==len)
            {
                for(int i=pos;i<=num;i++) st.push_back(i);
                vec.push_back(st);
                for(int i=pos;i<=num;i++) st.pop_back();
                return;
            }
        st.push_back(pos);
        generate(vec, st, pos+1, num, cnt+1, len);
        st.pop_back();
        generate(vec, st, pos+1, num, cnt, len);
    }

vector<vector<int> > combine(int n, int k)
    {
        vector<vector<int> > vec;
        vector<int> st;
        generate(vec, st, 1, n, 0, k);
    }