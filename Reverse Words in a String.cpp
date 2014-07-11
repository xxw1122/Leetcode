#include<iostream>
#include<string>
#include<vector>

using namespace std;

void Reverse(string &s)
    {
        int len=s.size();
        int i;
        char ch;
        for(i=0;i<len/2;i++)
            {
                ch=s[i];
                s[i]=s[len-1-i];
                s[len-1-i]=ch;
            }
    }


void reverseWords(string &s)
    {
        Reverse(s);
        string str="";
        int tag1=0,tag2=0,len=s.size();
        string st="";
        for(int i=0;i<len;i++)
        {
            if(tag1==0&&s[i]!=' ')
            {
                tag1=1;
                str="";
                str=str+s[i];
                if(i==len-1)
                    {
                        Reverse(str);
                        if(tag2==0)
                            {
                                st=st+str;
                                tag2=1;
                            }
                        else if(tag2==1)
                            {
                                st=st+" ";
                                st=st+str;
                            }
                    }
            }
            else if(tag1==1)
            {
                if(s[i]==' ')
                {
                    Reverse(str);
                    if(tag2==0)
                    {
                        st=st+str;
                        tag2=1;
                    }
                    else if(tag2==1)
                    {
                        st=st+" ";
                        st=st+str;
                    }
                    str="";
                    tag1=0;
                    continue;
                }
                if(i==len-1&&s[i]!=' ')
                {
                    str=str+s[i];
                    Reverse(str);
                    if(tag2==0)
                    {
                        st=st+str;
                        tag2=1;
                    }
                    else if(tag2==1)
                    {
                        st=st+" ";
                        st=st+str;
                    }
                    continue;
                }
                str=str+s[i];
            }
        }
        s=st;
    }

int main()
    {
        string str;
        while(getline(cin,str))
            {
                reverseWords(str);
                // Reverse(str);
                cout<<str<<endl;
            }
        return 0;
    }