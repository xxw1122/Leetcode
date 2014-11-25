#include<iostream>
#include<algorithm>
#include<vector>


static bool cmp(int x,int y)
    {
        return x<y;
    }

vector<vector<int> > permute(vector<int> &num)
    {
        vector<vector<int> > vec;
        sort(num.begin(),num.end(),cmp);
        vec.push_back(num);
        while(next_permutation(num.begin(),num.end()))
            {
                vec.push_back(num);
            }
        return vec;
    }

