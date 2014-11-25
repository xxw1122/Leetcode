#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> letterCombinations(string digits) {
    string s[10];
    s[0]="abc",s[1]="def",s[2]="ghi",s[3]="jkl",s[4]="mno",s[5]="pqrs",s[6]="tuv",s[7]="wxyz";
    vector<string> st1,st2;
    for(int i=0;i<digits.size();i++){
        if(digits[i]>='2'&&digits[i]<='9'){
            if(st1.size()==0){
                for(int j=0;j<s[digits[i]-'2'].size();j++){
                    string str(1,s[digits[i]-'2'][j]);
                    st2.push_back(str);
                }
                st1.assign(st2.begin(), st2.end());
                st2.clear();
            }
            else{
                for(int j=0;j<st1.size();j++){
                    for(int k=0;k<s[digits[i]-'2'].size();k++){
                        string str=st1[j]+s[digits[i]-'2'][k];
                        st2.push_back(str);
                    }
                }
                st1.assign(st2.begin(), st2.end());
                st2.clear();
            }
        }
    }
    if(st1.size()==0){
        st1.push_back("");
        return st1;
    }
    return st1;
}

int main(){
    string str;
    while(getline(cin,str)){
        vector<string> vec=letterCombinations(str);
        for(int i=0;i<vec.size();i++)
            cout<<vec[i]<<endl;
    }
}