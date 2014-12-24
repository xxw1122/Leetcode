class Solution {
public:
    string longestPalindrome(string s) {
        int dp[1010][1010];
        memset(dp,0,sizeof(dp));
        int len=s.size();
        for(int i=0;i<=len;i++){
            dp[i][i]=1;
        }
        int left = 0, right = 0, maxsub = 1;
        for(int i=2;i<=len;i++){
            for(int j=0;j+i-1<len;j++){
                int r=j+i-1;
                if(s[j]==s[r]){
                    if(j+1>=r-1 || dp[j+1][r-1] == 1){
                        dp[j][r] = 1;
                        if(r-j+1 > maxsub){
                            maxsub = r - j + 1;
                            left = j;
                            right = r;
                        }
                    }
                }
            }
        }
        str = "";
        for(int i = left; i <= right; i++){
            str += s[i];
        }
        return str;
    }
};