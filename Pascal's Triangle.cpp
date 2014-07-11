#include<iostream>
#include<vector>


vector<vector<int> > generate(int numRows)
    {
        vector<vector<int> >vec;
        if(numRows==0) return vec;
        vector<int> st;
        int cnt=1;
        st.push_back(cnt);
        vec.push_back(st);
        for(int i=2;i<=numRows;i++)
            {
                st.clear();
                st.push_back(cnt);
                for(int j=0;j+1<vec[i-2].size();j++)
                    {
                        int cur=vec[i-2][j]+vec[i-2][j+1];
                        st.push_back(cur);
                    }
                st.push_back(cnt);
                vec.push_back(st);
            }
        return vec;
    }