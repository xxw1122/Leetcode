#include<iostream>
#include<stack>
#include<string>
#include<vector>

using namespace std;

vector<string> vec;

stack<int> st1;
stack<string> st2;

int convert(string &str)
    {
        int sum=0,pos=0;
        if(str[0]=='-') pos=1;
        for(int i=pos;i<str.size();i++)
            sum=sum*10+str[i]-'0';
        if(str[0]=='-') return sum*-1;
        else return sum;
    }

int main()
    {
        string str;
        while(cin>>str&&str!="0")
            {
                vec.push_back(str);
            }
        int i,j,k;
        int x,y,z;
        for(i=0;i<vec.size();i++)
            {
                if((vec[i][0]>='0'&&vec[i][0]<='9')||(vec[i][0]=='-'&&vec[i].size()>1))
                    {
                        x=convert(vec[i]);
                        if(st1.size()>=1&&st2.size()>=1)
                            {
                                y=st1.top();
                                st1.pop();
                                if(st2.top()=="+")
                                    z=y+x;
                                else if(st2.top()=="-")
                                    z=y-x;
                                else if(st2.top()=="*")
                                    z=y*x;
                                else if(st2.top()=="/")
                                    z=y/x;
                                st2.pop();
                                st1.push(z);
                            }
                        else st1.push(x);
                    }
                else
                    {
                        if(st1.size()>=2)
                            {
                                x=st1.top();
                                st1.pop();
                                y=st1.top();
                                st1.pop();
                                if(vec[i]=="+")
                                    z=y+x;
                                else if(vec[i]=="-")
                                    z=y-x;
                                else if(vec[i]=="*")
                                    z=y*x;
                                else if(vec[i]=="/")
                                    z=y/x;
                                st1.push(z);
                            }
                        else st2.push(vec[i]);
                    }
            }
        //cout<<st1.size()<<endl;
        cout<<st1.top()<<endl;
        return 0;
    }