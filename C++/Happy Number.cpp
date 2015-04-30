class Solution {
public:
    int convert(int n) {
        int res = 0;
        while (n) {
            res += (n % 10) * (n % 10);
            n = n / 10;
        }
        return res;
    }
    set<int> st;
    bool isHappy(int n) {
        st.insert(n);
        int res = convert(n);
        if (res == 1) return true;
        else if (st.find(res) != st.end()) return false;
        else return isHappy(res);
    }
};