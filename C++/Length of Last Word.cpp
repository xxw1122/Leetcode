#include<iostream>
#include<cstring>

int lengthOfLastWord(const char *s)
    {
        int tag=0,len=strlen(s);
        int lenth=0;
        int res=0;
        for(int i=0;i<len;i++)
            {
                if(s[i]!=' '&&tag==0)
                    {
                        tag=1;
                        lenth++;
                        if(i==len-1) res=lenth;
                    }
                else if(s[i]!=' '&&tag==1)
                    {
                        lenth++;
                        if(i==len-1) res=lenth;
                    }
                else if(s[i]==' '&&tag==1)
                    {
                        tag=0;
                        res=lenth;
                        lenth=0;
                    }
            }
        return res;
    }