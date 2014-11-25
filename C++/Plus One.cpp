#include<iostream>
#include<vector>

vector<int> plusOne(vector<int> &digits)
    {
        int len=digits.size();
        int *arry=new int[len];
        for(int i=0;i<len;i++)
            arry[i]=digits[i];
        int pos=digits.size()-1;
        int d=1;
        while(pos>=0)
            {
                int cnt=(arry[pos]+d)/10;
                arry[pos]=(arry[pos]+d)%10;
                d=cnt;
                pos--;
                if(d==0) break;
            }
        vector<int> vec;
        if(d>0) vec.push_back(d);
        for(int i=0;i<len;i++)
            vec.push_back(arry[i]);
        return vec;
    }