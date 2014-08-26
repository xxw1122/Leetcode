#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    bool matrix[500][500];
    bool isMatch(const char *s, const char *p) {
        int slen = strlen(s);
        int plen = strlen(p);
        const char* tmp = p;
        int cnt = 0;
        while (*tmp != '\0') if (*(tmp++) != '*') cnt++;
        if (cnt > slen) return false;
        memset(matrix, 0, sizeof(matrix));
        matrix[0][0] = true; // i,j means length
        for (int i = 1; i <= plen; i++)
        {
            if (matrix[0][i-1] && p[i-1] == '*') matrix[0][i] = true;
            for (int j = 1; j <= slen; j++)
            {
                if (p[i-1] == '*')
                {
                    matrix[j][i] = (matrix[j-1][i] || matrix[j][i-1]);
                }
                else if (p[i-1] == '?' || p[i-1] == s[j-1])
                {
                    matrix[j][i] = matrix[j-1][i-1];
                }
                else
                {
                    matrix[j][i] = false;
                }
            }
        }
        return matrix[slen][plen];
    }
};