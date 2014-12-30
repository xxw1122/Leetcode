class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> >vec;
        sort(num.begin(), num.end());
        int len = num.size();
        for(int i = 0; i + 2 < len; i++){
            if(i == 0 || (i > 0 && num[i] != num[i-1])){
                int left = i + 1, right = len - 1;
                while(left < right){
                    int s = num[i] + num[left] + num[right];
                    if(s == 0){
                        vector<int> vec1;
                        vec1.push_back(num[i]);
                        vec1.push_back(num[left]);
                        vec1.push_back(num[right]);
                        vec.push_back(vec1);
                        left++;
                        right--;
                        while(left < right && num[left] == num[left-1])
                            left++;
                        while(left < right && num[right] == num[right+1])
                            right--;
                    }
                    else if(s < 0) left++;
                    else right--;
                }
            }
        }
        return vec;
    }
};