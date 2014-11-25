#include <string>
#include <vector>

using namespace std;

string convert(string s, int nRows) {
    if(s.size()<=1||nRows<=1) return s;
    vector<vector<char> >vec;
    vector<char>st;
    for(int i=0;i<nRows;i++)
        vec.push_back(st);
    int pos=0,len=s.size();
    int x=0;
    while(pos<len){
        while(pos<len&&x+1<nRows){
            vec[x].push_back(s[pos]);
            pos++;
            x++;
        }
        while(pos<len&&x-1>=0){
            vec[x].push_back(s[pos]);
            pos++;
            x--;
        }
    }
    string str="";
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++){
            str=str+vec[i][j];
        }
    }
    return str;
}
