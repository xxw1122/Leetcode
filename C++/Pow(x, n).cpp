class Solution {
public:
    double helper(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        double res = helper(x, n / 2);
        res = res * res;
        if (n % 2 == 1) {
            res = res * x;
        }
        return res;
    }
    double myPow(double x, int n) {
        if (n >= 0) return helper(x, n);
        else return 1.0 / helper(x, -n);
    }
};