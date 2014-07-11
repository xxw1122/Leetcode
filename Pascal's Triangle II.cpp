#include<iostream>
#include<vector>

vector<int> getRow(int rowIndex)
    {
        vector<int> st1;
        vector<int> st2;
        st1.push_back(1);
        for(int i=0;i<rowIndex;i++)
            {
                st2.push_back(1);
                int cnt;
                for(int j=0;j<st1.size()-1;j++)
                    {
                        cnt=st1[j]+st1[j+1];
                        st2.push_back(cnt);
                    }
                st2.push_back(1);
                st1=st2;
                st2.clear();
            }
        return st1;
    }