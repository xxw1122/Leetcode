#include<iostream>
#include<string>
#include<vector>


void generate(vector<string> &st,string &str,int leftnum,int rightnum,int lenth)
    {
        if(leftnum==lenth&&rightnum==lenth)
            {
                st.push_back(str);
                return;
            }
        else if(leftnum==lenth)
            {
                string str1=str+")";
                generate(st,str1,leftnum,rightnum+1,lenth);
            }
        else if(leftnum<lenth)
            {
                if(leftnum>rightnum)
                    {
                        string str1=str+")";
                        generate(st,str1,leftnum,rightnum+1,lenth);
                    }
                string str1=str+"(";
                generate(st,str1,leftnum+1,rightnum,lenth);
            }
    }

vector<string> generateParenthesis(int n)
    {
        vector<string> vec;
        if(n==0) return vec;
        string str="(";
        generate(vec,str,1,0,n);
        return vec;
    }