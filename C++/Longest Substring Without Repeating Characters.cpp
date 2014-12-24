class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> st;
        int length=0,len=s.size();
        int maxlength=0,start=0;
        for(int i=0;i<len;i++){
            if(st.count(s[i])==0){
                st.insert(make_pair(s[i],i));
                length++;
                maxlength=max(maxlength,length);
            }
            else if(st.count(s[i])==1){
                int pos=st[s[i]];
                if(pos<start){
                    st[s[i]]=i;
                    length++;
                    maxlength=max(maxlength,length);
                }
                else{
                    length=i-pos;
                    maxlength=max(maxlength,length);
                    st[s[i]]=i;
                    start=pos+1;
                }
            }
        }
        return maxlength;
    }
};