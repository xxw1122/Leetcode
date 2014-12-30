class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int len = num.size();
        sort(num.begin(), num.end());
        int res = num[0] + num[1] + num[2];
        for(int i = 0; i < len; i++){
            int left = i + 1, right = len - 1;
            while(left < right){
                int s = num[i]  + num[left] + num[right];
                if(abs(s - target) < abs(res - target)){
                    res = s;
                }
                if(s == target) return s;
                else if(s < target) left++;
                else right--;
            }
        }
        return res;
    }
};