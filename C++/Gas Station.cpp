class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cur = 0, pos = 0;
        for (int i = 0; i < gas.size(); i ++) {
            cur += (gas[i] - cost[i]);
            if (cur < 0) pos = i + 1;
        }
        return pos;
    }
};