#include <string>
#include <vector>

using namespace std;

string handle_normal(vector<string> &word, int L, int wordL){
    string str="";
    int num=word.size();
    if(num==1){
        str+=word[0];
        for(int i=0;i<L-wordL;i++){
            str+=" ";
        }
        return str;
    }
    int mean=(L-wordL)/(num-1);
    int remain=(L-wordL)%(num-1);
    str=word[0];
    for(int i=1;i<word.size();i++){
        for(int j=0;j<mean;j++)
            str+=" ";
        if(remain>0){
            str+=" ";
            remain--;
        }
        str+=word[i];
    }
    return str;
}

string handle_last(vector<string> &word,int L,int count){
    string str=word[0];
    for(int i=1;i<word.size();i++){
        str+=" "+word[i];
    }
    for(int i=0;i<L-count;i++)
        str+=" ";
    return str;
}


vector<string> fullJustify(vector<string> &words, int L){
    vector<string> vec,st;
    int count=-1,lenth=0;
    for(auto iter=words.begin();iter!=words.end();iter++){
        if(count+1+(*iter).length()>L){
            vec.push_back(handle_normal(st, L, lenth));
            st.clear();
            count=-1;
            lenth=0;
        }
        count+=1+(*iter).length();
        lenth+=(*iter).length();
        st.push_back(*iter);
    }
    vec.push_back(handle_last(st, L, count));
    return vec;
}