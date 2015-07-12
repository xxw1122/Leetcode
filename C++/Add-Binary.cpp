class Solution {
public:
    string addBinary(string a, string b) {
        vector<char> res;
        int d = 0, indexa = a.size() - 1, indexb = b.size() - 1;
        while (indexa >= 0 && indexb >= 0) {
            int temp = d + a[indexa--] - '0' + b[indexb--] - '0';
            res.push_back('0' + temp % 2);
            d = temp / 2;
        }
        while (indexa >= 0) {
            int temp = d + a[indexa--] - '0';
            res.push_back('0' + temp % 2);
            d = temp / 2;
        }
        while (indexb >= 0) {
            int temp = d + b[indexb--] - '0';
            res.push_back('0' + temp % 2);
            d = temp / 2;
        }
        if (d != 0) {
            res.push_back('0' + d);
        }
        int cur = res.size() - 1;
        while (cur >= 0 && res[cur] == '0') cur --;
        if (cur < 0) return "0";
        string str;
        for (int i = cur; i >= 0; i --) {
            str += res[i];
        }
        return str;
    }
};