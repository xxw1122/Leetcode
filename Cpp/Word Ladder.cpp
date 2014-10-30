#include <unordered_set>
#include <string>
#include <queue>
#include <map>

using namespace std;

int ladderLength(string start, string end, unordered_set<string> &dict){
  unordered_set<string>st;
  queue<pair<string,int> >que;
  st.insert(start);
  que.push(make_pair(start,1));
  while(!que.empty()){
    string str=que.front().first,s;
    int length=que.front().second;
    if(str==end) return length;
    length++;
    que.pop();
    for(int i=0;i<str.size();i++){
      for(int j=0;j<26;j++){
        s=str;
        s[i]='a'+j;
        if(st.count(s)==0&&dict.count(s)>0){
          st.insert(s);
          que.push(make_pair(s,length));
        }
      }
    }
  }
  return 0;
}
