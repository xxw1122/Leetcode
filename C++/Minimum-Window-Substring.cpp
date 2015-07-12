#include <string>
#include <cstring>

class Solution {
public:
    string minWindow(string S, string T) {
        if(S.empty()) return "";
        if(S.size() < T.size()) return "";
        const int ASCII_MAX = 256;
        int appeared_count[ASCII_MAX];
        int expected_count[ASCII_MAX];
        fill(appeared_count, appeared_count + ASCII_MAX, 0);
        fill(expected_count, expected_count + ASCII_MAX, 0);
        for(size_t i = 0; i < T.size(); i++){
            expected_count[T[i]]++;
        }
        int minwnd = INT_MAX, start = 0;
        int cnt = 0,appeared = 0;
        for(size_t i = 0; i < S.size(); i++){
            if(expected_count[S[i]] > 0){
                appeared_count[S[i]] ++;
                if(appeared_count[S[i]] <= expected_count[S[i]]){
                    appeared++;
                }
            }
            if(appeared == T.size()){
                while(appeared_count[S[cnt]] > expected_count[S[cnt]] || expected_count[S[cnt]] == 0){
                    appeared_count[S[cnt]]--;
                    cnt++;
                }
                if(i - cnt + 1 < minwnd){
                    minwnd = i - cnt + 1;
                    start = cnt;
                }
            }
        }
        if(minwnd == INT_MAX) return "";
        else return S.substr(start, minwnd);
    }
};