#include<iostream>
#include<string>

using namespace std;

int romanToInt(string s)
    {
        int sum=0,len=s.size();
        for(int i=0;i<len;i++)
            {
                if(s[i]=='I')
                    {
                        if(i<len-1&&(s[i+1]=='V'||s[i+1]=='X')) sum=sum-1;
                        else sum++;
                    }
                else if(s[i]=='V') sum=sum+5;
                else if(s[i]=='X')
                    {
                        if(i<len-1&&(s[i+1]=='L'||s[i+1]=='C'))
                            {
                                sum=sum-10;
                            }
                        else sum=sum+10;
                    }
                else if(s[i]=='L') sum=sum+50;
                else if(s[i]=='C')
                    {
                        if(i<len-1&&(s[i+1]=='D'||s[i+1]=='M'))
                            {
                                sum=sum-100;
                            }
                        else sum=sum+100;
                    }
                else if(s[i]=='D') sum=sum+500;
                else if(s[i]=='M') sum=sum+1000;
            }
        return sum;
    }