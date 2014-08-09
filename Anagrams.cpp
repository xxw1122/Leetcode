#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>
#include <map>

using namespace std;

vector<string> anagrams(vector<string> &strs) {
    vector<string> vec;
    if(strs.empty()) return vec;
    multimap<string,string> mp;
    multimap<string,string>::iterator pos;
    for(int i=0;i<strs.size();i++){
        string str1(strs[i]);
        sort(str1.begin(),str1.end());
        mp.insert(make_pair(str1, strs[i]));
    }
    for(int i=0;i<strs.size();i++){
        string str1=strs[i];
        sort(str1.begin(),str1.end());
        if(mp.count(str1)>=2){
            while(mp.count(str1)){
                pos=mp.find(str1);
                vec.push_back(pos->second);
                mp.erase(pos);
            }
        }
    }
    return vec;
}